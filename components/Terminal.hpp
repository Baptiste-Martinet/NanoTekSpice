/*
** EPITECH PROJECT, 2020
** FourAndGates.h
** File description:
** Temp
*/

#pragma once
#include "AComponent.hpp"

class Terminal : public nts::AComponent {
public:
    Terminal(const std::string &name);
    ~Terminal();
    nts::Tristate compute(std::size_t pin = 1) override;
};
