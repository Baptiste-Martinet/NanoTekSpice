/*
** EPITECH PROJECT, 2020
** DualFlipFlop.h
** File description:
** Temp
*/

#pragma once
#include "AComponent.hpp"

class DualFlipFlop : public nts::AComponent {
public:
    DualFlipFlop(const std::string &name, sf::Vector2f pos);
    ~DualFlipFlop();
    nts::Tristate compute(std::size_t pin = 1) override;

private:
    nts::Tristate mem1;
    nts::Tristate qmem1;
    nts::Tristate mem2;
    nts::Tristate qmem2;
};
