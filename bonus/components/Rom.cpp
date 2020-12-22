/*
** EPITECH PROJECT, 2020
** Rom.cpp
** File description:
** Temp
*/

#include "Rom.hpp"

Rom::Rom(const std::string &name) : AComponent(name) {

}

Rom::~Rom() {

}

nts::Tristate Rom::compute(std::size_t pin) {
    (void)pin;
    return nts::UNDEFINED;
}
