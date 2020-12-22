/*
** EPITECH PROJECT, 2020
** nanotekspice
** File description:
** desc
*/

#pragma once
#include "../AComponent.hpp"

class FourNorGates : public nts::AComponent
{
public:
    FourNorGates(const std::string &name);
    ~FourNorGates();
    nts::Tristate compute(std::size_t pin = 1) override;
};