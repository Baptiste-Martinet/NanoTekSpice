/*
** EPITECH PROJECT, 2020
** c4008.cpp
** File description:
** Temp
*/

#include "FourBitAdder.hpp"

FourBitAdder::FourBitAdder(const std::string &name) : AComponent(name) {
    this->_pins.push_back(new nts::Pin(this, "input"));     //A4 -> 0
    this->_pins.push_back(new nts::Pin(this, "input"));     //B3 -> 1
    this->_pins.push_back(new nts::Pin(this, "input"));     //A3 -> 2
    this->_pins.push_back(new nts::Pin(this, "input"));     //B2 -> 3
    this->_pins.push_back(new nts::Pin(this, "input"));     //A2 -> 4
    this->_pins.push_back(new nts::Pin(this, "input"));     //B1 -> 5
    this->_pins.push_back(new nts::Pin(this, "input"));     //A1 -> 6
    this->_pins.push_back(new nts::Pin(this, "vss"));       //VSS -> 7
    this->_pins.push_back(new nts::Pin(this, "input"));     //C1 -> 8
    this->_pins.push_back(new nts::Pin(this, "output"));    //S1 -> 9
    this->_pins.push_back(new nts::Pin(this, "output"));    //S2 -> 10
    this->_pins.push_back(new nts::Pin(this, "output"));    //S3 -> 11
    this->_pins.push_back(new nts::Pin(this, "output"));    //S4 -> 12
    this->_pins.push_back(new nts::Pin(this, "output"));    //C0 -> 13
    this->_pins.push_back(new nts::Pin(this, "input"));     //B4 -> 14
    this->_pins.push_back(new nts::Pin(this, "vdd"));       //VDD -> 15
}

FourBitAdder::~FourBitAdder() {

}

nts::Tristate FourBitAdder::compute(std::size_t pin) {
    pin--;
    if (pin >= this->_pins.size()) {
        std::cerr << "Wrong pin passed as parameter" << std::endl;
        return nts::Tristate::UNDEFINED;
    }
    std::pair<nts::Tristate, nts::Tristate> carry = fullAdder(this->_pins[6]->getState(), this->_pins[5]->getState(), this->_pins[8]->getState());
    this->_pins[9]->setState(carry.first);
    carry = fullAdder(this->_pins[4]->getState(), this->_pins[3]->getState(), carry.second);
    this->_pins[10]->setState(carry.first);
    carry = fullAdder(this->_pins[2]->getState(), this->_pins[1]->getState(), carry.second);
    this->_pins[11]->setState(carry.first);
    carry = fullAdder(this->_pins[0]->getState(), this->_pins[14]->getState(), carry.second);
    this->_pins[12]->setState(carry.first);
    this->_pins[13]->setState(carry.second);
    return (this->_pins[pin]->getStateNoCompute());
}

std::pair<nts::Tristate, nts::Tristate> FourBitAdder::fullAdder(nts::Tristate a, nts::Tristate b, nts::Tristate c) {
    nts::Tristate x1 = gate::Xor(a, b);
    nts::Tristate s1 = gate::And(x1, c);
    nts::Tristate s2 = gate::And(a, b);
    return std::make_pair(gate::Xor(x1, c), gate::Or(s1, s2));
}
