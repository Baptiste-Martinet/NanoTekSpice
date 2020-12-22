/*
** EPITECH PROJECT, 2020
** name
** File description:
** desc
*/

#include "Output.hpp"

Output::Output(const std::string &name) : AComponent(name)
{
    /* pin declarations */
    this->_pins.push_back(new nts::Pin(this, "input"));
}

Output::~Output()
{
}

nts::Tristate Output::compute(std::size_t pin)
{
    pin--;
    if (pin >= this->_pins.size()) {
        std::cerr << "Wrong pin passed as parameter" << std::endl;
        return nts::Tristate::UNDEFINED;
    }
    return (this->_pins[pin]->getState());
}