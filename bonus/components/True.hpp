/*
** EPITECH PROJECT, 2020
** name
** File description:
** desc
*/

#pragma once

#include "../AComponent.hpp"

class True : public nts::AComponent
{
public:
    True(const std::string &name, sf::Vector2f pos);
    ~True();
    nts::Tristate compute(std::size_t pin = 1) override;
};