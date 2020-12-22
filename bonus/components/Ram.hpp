/*
** EPITECH PROJECT, 2020
** Ram.h
** File description:
** Temp
*/

#pragma once
#include "AComponent.hpp"

class Ram : public nts::AComponent {
public:
    Ram(const std::string &name);
    ~Ram();
    nts::Tristate compute(std::size_t pin = 1) override;

};
