/*
** EPITECH PROJECT, 2020
** FourOrGates.cpp
** File description:
** Temp
*/

#include "FourOrGates.hpp"

FourOrGates::FourOrGates(const std::string &name, sf::Vector2f pos) : AComponent(name) {
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
    if (!_textures[0].loadFromFile("textures/command_block.png"))
        exit(84);
    this->_text.setString("||");
    createRectangle(this->_rect, pos, (sf::Vector2f){100,100}, (sf::Color){255,255,255}, 0, (sf::Color){255,255,255}, &_textures[0]);
}

FourOrGates::~FourOrGates() {

}

nts::Tristate FourOrGates::compute(std::size_t pin) {
    pin--;
    if (pin >= this->_pins.size()) {
        std::cerr << "Wrong pin passed as parameter" << std::endl;
        return nts::Tristate::UNDEFINED;
    }
    if (pin == 2)
        this->_pins[2]->setState(gate::Or(this->_pins[0]->getState(), this->_pins[1]->getState()));
    if (pin == 3)
        this->_pins[3]->setState(gate::Or(this->_pins[4]->getState(), this->_pins[5]->getState()));
    if (pin == 9)
        this->_pins[9]->setState(gate::Or(this->_pins[7]->getState(), this->_pins[8]->getState()));
    if (pin == 10)
        this->_pins[10]->setState(gate::Or(this->_pins[11]->getState(), this->_pins[12]->getState()));
    return (this->_pins[pin]->getStateNoCompute());
}
