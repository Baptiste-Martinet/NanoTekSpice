/*
** EPITECH PROJECT, 2020
** DualFlipFlop.cpp
** File description:
** Temp
*/

#include "DualFlipFlop.hpp"

DualFlipFlop::DualFlipFlop(const std::string &name, sf::Vector2f pos) : AComponent(name) {
    this->_pins.push_back(new nts::Pin(this, "output")); // Q1
    this->_pins.push_back(new nts::Pin(this, "output")); // NOT Q1
    this->_pins.push_back(new nts::Pin(this, "input")); // CLOCK 1
    this->_pins.push_back(new nts::Pin(this, "input")); // RESET 1
    this->_pins.push_back(new nts::Pin(this, "input")); // DATA 1
    this->_pins.push_back(new nts::Pin(this, "input")); // SET 1
    this->_pins.push_back(new nts::Pin(this, "vss")); // vSS
    this->_pins.push_back(new nts::Pin(this, "input")); // SET 2
    this->_pins.push_back(new nts::Pin(this, "input")); // DATA 2
    this->_pins.push_back(new nts::Pin(this, "input")); // RESET 2
    this->_pins.push_back(new nts::Pin(this, "input")); // CLOCK 2
    this->_pins.push_back(new nts::Pin(this, "output")); // Q2
    this->_pins.push_back(new nts::Pin(this, "output")); // NOT Q2
    this->_pins.push_back(new nts::Pin(this, "vdd")); // vdd

    this->mem1 = nts::UNDEFINED;
    this->mem2 = nts::UNDEFINED;
    //sfml
     if (!_textures[0].loadFromFile("textures/command_block.png"))
        exit(84);
    this->_text.setString("N&");
    createRectangle(this->_rect, pos, (sf::Vector2f){100,100}, (sf::Color){255,255,255}, 0, (sf::Color){255,255,255}, &_textures[0]);
}

DualFlipFlop::~DualFlipFlop() {

}

nts::Tristate DualFlipFlop::compute(std::size_t pin) {
    pin--;
    if (this->_pins.size() <= pin) {
        std::cerr << "Wrong pin passed as parameter" << std::endl;
        return (nts::UNDEFINED);
    }
    nts::Tristate clock1 = this->_pins[2]->getStateNoCompute();
    nts::Tristate clock2 = this->_pins[2]->getStateNoCompute();
    // FLIP 1
    if (clock1 == nts::TRUE) {
        mem1 = (this->_pins[4]->getState() != nts::UNDEFINED ? this->_pins[4]->getStateNoCompute() : nts::UNDEFINED);
        this->_pins[0]->setState(mem1);
        this->_pins[1]->setState(gate::Not(mem1));
    }
    if (this->_pins[5]->getState() != nts::UNDEFINED || this->_pins[3]->getState() != nts::UNDEFINED) {
        if (this->_pins[5]->getStateNoCompute() == nts::TRUE && this->_pins[3]->getStateNoCompute() != nts::TRUE) {
            mem1 = nts::TRUE;
            qmem1 = nts::FALSE;
        }
        if (this->_pins[5]->getStateNoCompute() != nts::TRUE && this->_pins[3]->getStateNoCompute() == nts::TRUE) {
            mem1 = nts::FALSE;
            qmem1 = nts::TRUE;
        }
        if (this->_pins[5]->getStateNoCompute() == nts::TRUE && this->_pins[3]->getState() == nts::TRUE) {
            mem1 = nts::TRUE;
            qmem1 = nts::TRUE;
        }
    }

    // FLIP 2
    if (clock2 == nts::TRUE) {
        mem1 = (this->_pins[4]->getState() != nts::UNDEFINED ? this->_pins[4]->getStateNoCompute() : nts::UNDEFINED);
        this->_pins[11]->setState(mem1);
        this->_pins[12]->setState(gate::Not(mem1));
    }
    if (this->_pins[7]->getState() != nts::UNDEFINED || this->_pins[9]->getState() != nts::UNDEFINED) {
        if (this->_pins[7]->getStateNoCompute() == nts::TRUE && this->_pins[9]->getStateNoCompute() != nts::TRUE) {
            mem1 = nts::TRUE;
            qmem1 = nts::FALSE;
        }
        if (this->_pins[7]->getStateNoCompute() != nts::TRUE && this->_pins[9]->getStateNoCompute() == nts::TRUE) {
            mem1 = nts::FALSE;
            qmem1 = nts::TRUE;
        }
        if (this->_pins[7]->getStateNoCompute() == nts::TRUE && this->_pins[9]->getState() == nts::TRUE) {
            mem1 = nts::TRUE;
            qmem1 = nts::TRUE;
        }
    }
    return (this->_pins[pin]->getStateNoCompute());
}
