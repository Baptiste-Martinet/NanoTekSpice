/*
** EPITECH PROJECT, 2020
** TwelveBitCounter.cpp
** File description:
** Temp
*/

#include "TwelveBitCounter.hpp"

TwelveBitCounter::TwelveBitCounter(const std::string &name) : AComponent(name) {

}

TwelveBitCounter::~TwelveBitCounter() {

}

nts::Tristate TwelveBitCounter::compute(std::size_t pin) {
    (void)pin;
    return nts::UNDEFINED;
}
