/*
** EPITECH PROJECT, 2020
** name
** File description:
** desc
*/

#include "False.hpp"

False::False(const std::string &name, sf::Vector2f pos) : AComponent(name)
{
    /* pin declarations */
    this->_pins.push_back(new nts::Pin(this, "output", nts::Tristate::FALSE));
    if (!_textures[0].loadFromFile("textures/32/redstone_torch_off.png"))
        exit(84);
    createRectangle(this->_rect, pos, (sf::Vector2f){100,100}, (sf::Color){255,255,255}, 0, (sf::Color){255,255,255}, &_textures[0]);
}

False::~False()
{
}

nts::Tristate False::compute(std::size_t pin)
{
    pin--;
    if (pin >= this->_pins.size()) {
        std::cerr << "Wrong pin passed as parameter" << std::endl;
        return nts::Tristate::UNDEFINED;
    }
    return (this->_pins.at(pin)->getStateNoCompute());
}