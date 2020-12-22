/*
** EPITECH PROJECT, 2020
** name
** File description:
** desc
*/

#include "components/Output.hpp"
#include "AComponent.hpp"

nts::AComponent::AComponent(const std::string &name)
{
    this->_name = name;
    this->_type = "unknown";

    if (!this->_font.loadFromFile("fonts/nk57-monospace-sc-sb.ttf"))
        exit(84);
    this->_text.setString("Null");
    this->_text.setFillColor(sf::Color::White);
    this->_text.setCharacterSize(25);
    this->_text.setFont(this->_font);
}

nts::AComponent::~AComponent()
{
}

nts::Pin *nts::AComponent::getPin(size_t indxPin) const
{
    indxPin--;
    if (indxPin >= this->_pins.size()) {
        throw Error("ERROR: You tried to access a pin that does not exist");
        return nullptr;
    }
    return (this->_pins.at(indxPin));
}

std::string nts::AComponent::getName() const
{
    return (this->_name);
}

size_t nts::AComponent::getNbPins() const
{
    return (this->_pins.size());
}

void nts::AComponent::setLink(std::size_t pin, nts::IComponent *other, std::size_t otherPin)
{
    pin--;
    if (pin >= this->_pins.size() || otherPin > other->getNbPins()) {
        throw Error("Tried to access non existent pin");
        return;
    }
    if (this->_pins.at(pin)->getType() == other->getPin(otherPin)->getType()) {
        throw Error("[ERROR]: You can't link same type pins");
        return;
    }
    this->_pins.at(pin)->addLink(other->getPin(otherPin));
}

size_t nts::AComponent::getPinIndx(nts::Pin *pin) const
{
    for (size_t i = 0; i < this->_pins.size(); i++) {
        if (this->_pins.at(i) == pin)
            return (i);
    }
    return (0);
}

void nts::AComponent::dump() const
{
    std::cout << "Dumping: " << this->_name << std::endl;
    for (size_t i = 0; i < this->_pins.size(); i++) {
        std::cout <<  "Pin" << (i+1) << ": " << (this->_pins.at(i)->getStateNoCompute() == nts::Tristate::UNDEFINED ? "U" : std::to_string(this->_pins.at(i)->getStateNoCompute())) << std::endl;
        std::vector<std::tuple<size_t, std::string>> test = this->_pins.at(i)->getLinksIndexes();
        for (size_t i = 0; i < test.size(); i++) {
            std::cout << "\t" << std::get<1>(test.at(i)) << ":" << (std::get<0>(test.at(i))+1) << std::endl;
        }
    }
}

void nts::AComponent::setName(const std::string &newName)
{
    this->_name = newName;
}

sf::RectangleShape &nts::AComponent::getRect()
{
    return (this->_rect);
}

void nts::AComponent::displayPin(sf::RenderWindow &window)
{
    size_t i = 0;

    for (nts::Pin *pin : this->_pins) {
        if (pin->getType() == "output") {
            pin->displayLinks(window, i);
            i++;
        }
    }
}

std::string nts::AComponent::getType() const
{
    return (this->_type);
}

sf::Texture &nts::AComponent::getTexture(size_t idx)
{
    return (this->_textures[idx]);
}

sf::Text &nts::AComponent::getText()
{
    return (this->_text);
}