/*
** EPITECH PROJECT, 2020
** FourAndGates.cpp
** File description:
** Temp
*/

#include "FourAndGates.hpp"

FourAndGates::FourAndGates(const std::string &name) : AComponent(name) {
    this->_pins.push_back(new nts::Pin(this, "input")); //0
    this->_pins.push_back(new nts::Pin(this, "input")); //1
    this->_pins.push_back(new nts::Pin(this, "output")); //2 <- 0 XOR 1
    this->_pins.push_back(new nts::Pin(this, "output")); //3 <- 4 XOR 5
    this->_pins.push_back(new nts::Pin(this, "input")); //4
    this->_pins.push_back(new nts::Pin(this, "input")); //5
    this->_pins.push_back(new nts::Pin(this, "vss")); //6
    this->_pins.push_back(new nts::Pin(this, "input")); //7
    this->_pins.push_back(new nts::Pin(this, "input")); //8
    this->_pins.push_back(new nts::Pin(this, "output")); //9
    this->_pins.push_back(new nts::Pin(this, "output")); //10
    this->_pins.push_back(new nts::Pin(this, "input")); //11
    this->_pins.push_back(new nts::Pin(this, "input")); //12
    this->_pins.push_back(new nts::Pin(this, "vdd")); //13
}

FourAndGates::~FourAndGates() {
}

nts::Tristate FourAndGates::compute(std::size_t pin) {
    pin--;
    if (pin >= this->_pins.size()) {
        std::cerr << "Wrong pin passed as parameter" << std::endl;
        return nts::Tristate::UNDEFINED;
    }
    if (pin == 2)
        this->_pins[2]->setState(gate::And(this->_pins[0]->getState(), this->_pins[1]->getState()));
    if (pin == 3)
        this->_pins[3]->setState(gate::And(this->_pins[4]->getState(), this->_pins[5]->getState()));
    if (pin == 9)
        this->_pins[9]->setState(gate::And(this->_pins[7]->getState(), this->_pins[8]->getState()));
    if (pin == 10)
        this->_pins[10]->setState(gate::And(this->_pins[11]->getState(), this->_pins[12]->getState()));
    return (this->_pins.at(pin)->getStateNoCompute());
}
