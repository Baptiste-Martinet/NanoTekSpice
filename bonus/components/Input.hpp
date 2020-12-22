/*
** EPITECH PROJECT, 2020
** name
** File description:
** desc
*/

#pragma once

#include "../AComponent.hpp"

class Input : public nts::AComponent
{
public:
    Input(const std::string &name, sf::Vector2f pos);
    ~Input();
    nts::Tristate compute(std::size_t pin = 1) override;
};