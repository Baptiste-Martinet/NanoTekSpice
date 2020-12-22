/*
** EPITECH PROJECT, 2020
** Ram.cpp
** File description:
** Temp
*/

#include "Ram.hpp"

Ram::Ram(const std::string &name) : AComponent(name) {

}

Ram::~Ram() {

}

nts::Tristate Ram::compute(std::size_t pin) {
    (void)pin;
    return nts::UNDEFINED;
}
