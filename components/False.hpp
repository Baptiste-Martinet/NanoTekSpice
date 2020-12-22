/*
** EPITECH PROJECT, 2020
** name
** File description:
** desc
*/

#pragma once

#include "../AComponent.hpp"

class False : public nts::AComponent
{
public:
    False(const std::string &name);
    ~False();
    nts::Tristate compute(std::size_t pin = 1) override;
};