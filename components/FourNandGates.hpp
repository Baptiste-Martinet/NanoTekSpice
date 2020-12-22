/*
** EPITECH PROJECT, 2020
** nanotekspice
** File description:
** desc
*/

#pragma once
#include "../AComponent.hpp"

class FourNandGates : public nts::AComponent
{
public:
    FourNandGates(const std::string &name);
    ~FourNandGates();
    nts::Tristate compute(std::size_t pin = 1) override;
};