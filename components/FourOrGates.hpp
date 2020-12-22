/*
** EPITECH PROJECT, 2020
** FourOrGates.h
** File description:
** Temp
*/

#pragma once
#include "AComponent.hpp"

class FourOrGates : public nts::AComponent {
public:
    FourOrGates(const std::string &name);
    ~FourOrGates();
    nts::Tristate compute(std::size_t pin = 1) override;

};
