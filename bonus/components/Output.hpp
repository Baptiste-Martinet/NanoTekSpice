/*
** EPITECH PROJECT, 2020
** name
** File description:
** desc
*/

#pragma once

#include "../AComponent.hpp"

class Output : public nts::AComponent
{
public:
    Output(const std::string &name, sf::Vector2f pos);
    ~Output();
    nts::Tristate compute(std::size_t pin = 1) override;
};