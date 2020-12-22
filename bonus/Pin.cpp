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
    if (this->_component->getType() == "input" || this->_component->getType() == "output" || this->_component->getType() == "clock")
        this->_component->getRect().setTexture(&this->_component->getTexture((state == nts::TRUE ? 1 : 0)));
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

void nts::Pin::displayLinks(sf::RenderWindow &window, size_t i)
{
    sf::VertexArray line(sf::LinesStrip, 2);

    for (nts::Pin *link : this->_links) {
        line[0] = sf::Vertex(this->_component->getRect().getPosition() + sf::Vector2f(100, 30 + i * 6), (this->_state == UNDEFINED ? sf::Color::Black : (this->_state == FALSE ? sf::Color(140, 0, 0) : sf::Color::Red)));
        line[1] = sf::Vertex(link->getComponent()->getRect().getPosition() + sf::Vector2f(0, 30 + link->getComponent()->getPinIndx(link) * 6), (this->_state == UNDEFINED ? sf::Color::Black : (this->_state == FALSE ? sf::Color(140, 0, 0) : sf::Color::Red)));
        window.draw(line);
    }
}