/*
** EPITECH PROJECT, 2020
** SixInverterGates.h
** File description:
** Temp
*/

#pragma once
#include "AComponent.hpp"

class SixInverterGates : public nts::AComponent {
public:
    SixInverterGates(const std::string &name);
    ~SixInverterGates();
    nts::Tristate compute(std::size_t pin = 1) override;

};
