/*
** EPITECH PROJECT, 2020
** name
** File description:
** desc
*/

#pragma once

#include "../AComponent.hpp"

class Clock : public nts::AComponent
{
public:
    Clock(const std::string &name, sf::Vector2f pos);
    ~Clock();
    nts::Tristate compute(std::size_t pin = 1) override;
};