/*
** EPITECH PROJECT, 2020
** FourAndGates.h
** File description:
** Temp
*/

#pragma once
#include "AComponent.hpp"

class FourAndGates : public nts::AComponent {
public:
    FourAndGates(const std::string &name);
    ~FourAndGates();
    nts::Tristate compute(std::size_t pin = 1) override;

};
