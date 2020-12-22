/*
** EPITECH PROJECT, 2020
** EightBitShiftRegister.cpp
** File description:
** Temp
*/

#include "EightBitShiftRegister.hpp"

EightBitShiftRegister::EightBitShiftRegister(const std::string &name) : AComponent(name) {

}

EightBitShiftRegister::~EightBitShiftRegister() {

}

nts::Tristate EightBitShiftRegister::compute(std::size_t pin) {
    (void)pin;
    return nts::UNDEFINED;
}
