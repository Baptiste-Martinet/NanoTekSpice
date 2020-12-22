/*
** EPITECH PROJECT, 2020
** nanotekspice
** File description:
** desc
*/

#include "Circuit.hpp"

Circuit::Circuit(const std::string &name) : AComponent(name)
{
}

Circuit::~Circuit()
{
}

void Circuit::addComponent(nts::IComponent *component)
{
    this->_components.push_back(component);
}

nts::IComponent *Circuit::getComponentAt(size_t idx) const
{
    if (idx >= this->_components.size())
        return nullptr;
    return (this->_components.at(idx));
}

nts::IComponent *Circuit::getComponentByName(std::string const name) const
{
    for (unsigned int i = 0; i < this->_components.size(); i++) {
        if (this->_components.at(i)->getName() == name) {
            return (this->_components.at(i));
        }
    }
    throw(Error("Component " + name + " does not exist"));
    return nullptr;
}

void Circuit::updateClocks()
{
    nts::Pin *pin;

    for (nts::IComponent *component : this->_components) {
        if (dynamic_cast<Clock *>(component)) {
            pin = component->getPin(1);
            switch (pin->getStateNoCompute()) {
                case nts::Tristate::UNDEFINED: pin->setState(nts::Tristate::FALSE);
                break;
                case nts::Tristate::FALSE: pin->setState(nts::Tristate::TRUE);
                break;
                case nts::Tristate::TRUE: pin->setState(nts::Tristate::FALSE);
                break;
            }
        }
    }
}

nts::Tristate Circuit::compute(std::size_t pin)
{
    for (size_t i = 0; i < this->_components.size(); i++) {
        if (dynamic_cast<Output *>(this->_components.at(i)) || dynamic_cast<Terminal *>(this->_components.at(i))) {
            this->_components.at(i)->compute();
        }
    }
    if (pin == 2) {
        Circuit::display();
    }
    Circuit::updateClocks();
    return (nts::Tristate::UNDEFINED);
}

void Circuit::createLinkFromString(std::string const line)
{
    std::vector<std::string> tokens;

    //std::cout << "-" << line << std::endl;
    splitToArray(line, tokens, " \t:");
    if (tokens.size() >= 4) {
        try {
        Circuit::getComponentByName(tokens.at(0))->setLink(std::stoi(tokens.at(1)), getComponentByName(tokens.at(2)), std::stoi(tokens.at(3)));
        Circuit::getComponentByName(tokens.at(2))->setLink(std::stoi(tokens.at(3)), getComponentByName(tokens.at(0)), std::stoi(tokens.at(1)));
        } catch (Error& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            exit(84);
        }
    }
}

void Circuit::createFromFile(std::string const filepath)
{
    std::ifstream file(filepath);
    std::string line;
    std::smatch match;
    std::string parseStatus = "none";
    nts::Factory factory;
    nts::IComponent *tmp;
    std::vector<nts::Tristate> states = {nts::Tristate::FALSE, nts::Tristate::TRUE};
    std::vector<std::string> tokens;

    if (!file)
        throw Error("Error: File does not exist");
    while (std::getline(file, line)) {
        std::regex_search(line, match, (std::regex)"^[^#]+");
        if (match.size() > 0) {
            line = match[0];
        } else {
            continue;
        }
        if (line.find(".chipsets:") != std::string::npos) {
            if (parseStatus == "chipsets") {
                throw Error("Chipset flag already defined");
            }
            parseStatus = "chipsets";
            continue;
        }
        if (line.find(".links:") != std::string::npos) {
            if (parseStatus == "links")
                throw Error("Links flag already defined");
            parseStatus = "links";
            continue;
        }
        /* parsing chipsets */
        line = std::regex_replace(line, (std::regex)"\\s+", " ");
        std::regex_search(line, match, (std::regex)"^\\w+\\s+[^:\\s]+(\\s\\([01]+\\))?"); //^\\w+\\s\\w+(\\s\\(\\d+\\))?
        if (match.size() > 0) {
            if (parseStatus == "chipsets") {
                tokens.clear();
                splitToArray(line, tokens, " \t");
                try {
                    if ((tmp = factory.createComponent(tokens.at(0), tokens.at(1)))) {
                        std::regex_search(line, match, (std::regex)"\\([01]\\)");
                        if (match.size() == 1)
                            tmp->getPin(1)->setState(states.at(std::stoi(line.substr(line.find("(")+1, line.find(")")))));
                        this->_components.push_back(tmp);
                    }
                } catch (Error& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                    exit(84);
                }
               continue;
            } else {
                throw Error("Tried to create component not in '.chipsets:' section");
            }
        }
        /* parsing links */
        std::regex_search(line, match, (std::regex)"^\\S+:\\d+\\s+\\S+:\\d+"); //^\\w+:+\\d+\\s+\\w+:\\d+
        if (match.size() > 0) {
            if (parseStatus == "links") {
                createLinkFromString(line);
                continue;
            } else {
                throw Error("Tried to link component not in the '.links:' section");
            }
        }
    }
    if (parseStatus != "links")
        throw Error("Invalid file format (Parser didn't reach '.links:' section");
    Circuit::sortComponentsByName();
}

void Circuit::dump() const
{
    std::cout << "There are " << this->_components.size() << " chipset(s) loaded in the circuit" << std::endl;
    for (auto component : this->_components) {
        std::cout << std::endl;
        component->dump();
    }
}

void Circuit::sortComponentsByName()
{
    std::sort(this->_components.begin(), this->_components.end(), [ ](const nts::IComponent *i1, const nts::IComponent *i2) {
        return (i1->getName() < i2->getName());
    });
}

void Circuit::display() const
{
    for (nts::IComponent *component : this->_components) {
        if (dynamic_cast<Output *>(component))
            std::cout << component->getName() << "=" << (component->getPin(1)->getStateNoCompute() == nts::UNDEFINED ? "U" : std::to_string(component->getPin(1)->getStateNoCompute())) << std::endl;
    }
}

bool Circuit::setInputStateByString(std::string str, bool isArgs)
{
    std::smatch match;
    std::vector<nts::Tristate> states = {nts::Tristate::FALSE, nts::Tristate::TRUE};
    nts::IComponent *component;

    std::regex_search(str, match, (std::regex)"^\\S+=[01]$");
    if (match.size() == 1) {
        try {
            component = Circuit::getComponentByName(str.substr(0, str.find("=")));
        } catch (Error& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            if (isArgs)
                exit(84);
            return true;
        }
        if (!component) {
            return (true);
        }
        if (!dynamic_cast<Input *>(component) && !dynamic_cast<Clock *>(component)) {
            throw Error("Component " + component->getName() + " is not an input");
            return (false);
        }
        component->getPin(1)->setState(states.at(std::stoi(str.substr(str.find("=")+1))));
    } else {
        if (!isArgs)
            return (false);
        throw Error("Wrong input definition formating");
    }
    return (true);
}

void Circuit::initInputsByArgs(int ac, char **av)
{
    std::string arg;

    for (int i = 2; i < ac; i++) {
        arg = std::string(av[i]);
        try {
            Circuit::setInputStateByString(arg, true);
        } catch (Error &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            exit(84);
        }
    }
    try {
        Circuit::IOerrorGestion();
    } catch (Error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(84);
    }
}

void Circuit::IOerrorGestion()
{
    for (nts::IComponent *component : this->_components) {
        if (dynamic_cast<Input *>(component)) {
            if (component->getPin(1)->getStateNoCompute() == nts::Tristate::UNDEFINED) {
                throw Error("All input need to be defined before the simulation starts");
            }
        } else if (dynamic_cast<Output *>(component)) {
            if (component->getPin(1)->getNbLinks() <= 0) {
                throw Error("Output ‘" + component->getName() + "’ is not linked to anything.");
            }
        }
    }
}