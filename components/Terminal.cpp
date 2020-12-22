/*
** EPITECH PROJECT, 2020
** Terminal.cpp
** File description:
** Temp
*/

#include "Terminal.hpp"
#include <cmath>

Terminal::Terminal(const std::string &name) : AComponent(name) {
    this->_pins.push_back(new nts::Pin(this, "input")); //0
    this->_pins.push_back(new nts::Pin(this, "input")); //1
    this->_pins.push_back(new nts::Pin(this, "input")); //2
    this->_pins.push_back(new nts::Pin(this, "input")); //3
    this->_pins.push_back(new nts::Pin(this, "input")); //4
    this->_pins.push_back(new nts::Pin(this, "input")); //5
    this->_pins.push_back(new nts::Pin(this, "input")); //6
    this->_pins.push_back(new nts::Pin(this, "input")); //7
    this->_pins.push_back(new nts::Pin(this, "input")); //8
    this->_pins.push_back(new nts::Pin(this, "input")); //9 print
}

Terminal::~Terminal() {
}

nts::Tristate Terminal::compute(std::size_t pin) {
    pin--;
    if (pin >= this->_pins.size()) {
        std::cerr << "Wrong pin passed as parameter" << std::endl;
        return nts::Tristate::UNDEFINED;
    }
    char test = 0;

    for (size_t i = 0; i < 9; i++) {
        if (this->_pins.at(i)->getState() == nts::TRUE)
            test += pow(2, i);
    }
    if (this->_pins.at(9)->getState() == nts::Tristate::TRUE)
        std::cout << "Terminal result: [" << test << "]" << std::endl;
    return (this->_pins.at(pin)->getStateNoCompute());
}
