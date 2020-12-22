/*
** EPITECH PROJECT, 2020
** FourXorGates.h
** File description:
** Temp
*/

#pragma once
#include "AComponent.hpp"

class FourXorGates : public nts::AComponent {
public:
    FourXorGates(const std::string &name, sf::Vector2f pos);
    ~FourXorGates();
    nts::Tristate compute(std::size_t pin = 1) override;
};
