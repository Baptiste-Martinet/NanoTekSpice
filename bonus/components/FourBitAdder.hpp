/*
** EPITECH PROJECT, 2020
** c4008.h
** File description:
** Temp
*/

#pragma once
#include "AComponent.hpp"

class FourBitAdder : public nts::AComponent {
public:
    FourBitAdder(const std::string &name, sf::Vector2f pos);
    ~FourBitAdder();
    nts::Tristate compute(std::size_t pin = 1) override;
    std::pair<nts::Tristate, nts::Tristate> fullAdder(nts::Tristate a, nts::Tristate b, nts::Tristate c);
};
