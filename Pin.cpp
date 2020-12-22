/*
** EPITECH PROJECT, 2020
** name
** File description:
** desc
*/

#include "IComponent.hpp"

nts::Pin::Pin(nts::IComponent *component, const std::string &type, nts::Tristate state)
{
    this->_state = state;
    this->_type = type;
    this->_component = component;
}

nts::Pin::~Pin()
{
}

nts::Tristate nts::Pin::getState()
{
    nts::Tristate state;

    if (this->_type == "input") {
        if (this->_links.size() <= 0)
            return (this->_state);
        this->_state = this->_links.at(0)->getState();
        for (size_t i = 1; i < this->_links.size(); i++) {
            if ((state = this->_links.at(i)->getState()) > this->_state)
                this->_state = state;
        }
    } else if (this->_type == "output") {
        this->_component->compute(this->_component->getPinIndx(this)+1);
    }
    return (this->_state);
}

nts::Tristate nts::Pin::getStateNoCompute() const
{
    return (this->_state);
}

void nts::Pin::setState(nts::Tristate state)
{
    this->_state = state;
}

void nts::Pin::addLink(Pin *otherPin)
{
    this->_links.push_back(otherPin);
}

std::string nts::Pin::getType() const
{
    return (this->_type);
}

std::vector<std::tuple<size_t, std::string>> nts::Pin::getLinksIndexes() const
{
    std::vector<std::tuple<size_t, std::string>> tmp;

    for (size_t i = 0; i < this->_links.size(); i++) {
        tmp.push_back(std::make_tuple(this->_links.at(i)->getComponent()->getPinIndx(this->_links.at(i)), this->_links.at(i)->getComponent()->getName()));
    }
    return (tmp);
}

nts::IComponent *nts::Pin::getComponent() const
{
    return (this->_component);
}

size_t nts::Pin::getNbLinks() const
{
    return (this->_links.size());
}