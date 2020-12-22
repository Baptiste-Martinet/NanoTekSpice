/*
** EPITECH PROJECT, 2020
** SixInverterGates.cpp
** File description:
** Temp
*/

#include "SixInverterGates.hpp"

SixInverterGates::SixInverterGates(const std::string &name) : AComponent(name) {
    this->_pins.push_back(new nts::Pin(this, "input")); //0
    this->_pins.push_back(new nts::Pin(this, "output")); //1
    this->_pins.push_back(new nts::Pin(this, "input")); //2
    this->_pins.push_back(new nts::Pin(this, "output")); //3
    this->_pins.push_back(new nts::Pin(this, "input")); //4
    this->_pins.push_back(new nts::Pin(this, "output")); //5
    this->_pins.push_back(new nts::Pin(this, "vss")); //6
    this->_pins.push_back(new nts::Pin(this, "output")); //7
    this->_pins.push_back(new nts::Pin(this, "input")); //8
    this->_pins.push_back(new nts::Pin(this, "output")); //9
    this->_pins.push_back(new nts::Pin(this, "input")); //10
    this->_pins.push_back(new nts::Pin(this, "output")); //11
    this->_pins.push_back(new nts::Pin(this, "input")); //12
    this->_pins.push_back(new nts::Pin(this, "vdd")); //13
}

SixInverterGates::~SixInverterGates() {

}

nts::Tristate SixInverterGates::compute(std::size_t pin) {
    pin--;
    if (pin >= this->_pins.size()) {
        std::cerr << "Wrong pin passed as parameter" << std::endl;
        return nts::Tristate::UNDEFINED;
    }
    if (pin == 1)
        this->_pins[1]->setState(gate::Not(this->_pins[0]->getState()));
    if (pin == 3)
        this->_pins[3]->setState(gate::Not(this->_pins[2]->getState()));
    if (pin == 5)
        this->_pins[5]->setState(gate::Not(this->_pins[4]->getState()));
    if (pin == 7)
        this->_pins[7]->setState(gate::Not(this->_pins[8]->getState()));
    if (pin == 9)
        this->_pins[9]->setState(gate::Not(this->_pins[10]->getState()));
    if (pin == 11)
        this->_pins[11]->setState(gate::Not(this->_pins[12]->getState()));
    return (this->_pins[pin]->getStateNoCompute());
}
