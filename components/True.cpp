/*
** EPITECH PROJECT, 2020
** name
** File description:
** desc
*/

#include "True.hpp"

True::True(const std::string &name) : AComponent(name)
{
    /* pin declarations */
    this->_pins.push_back(new nts::Pin(this, "output", nts::Tristate::TRUE));
}

True::~True()
{
}

nts::Tristate True::compute(std::size_t pin)
{
    pin--;
    if (pin >= this->_pins.size()) {
        std::cerr << "Wrong pin passed as parameter" << std::endl;
        return nts::Tristate::UNDEFINED;
    }
    return (this->_pins.at(pin)->getStateNoCompute());
}