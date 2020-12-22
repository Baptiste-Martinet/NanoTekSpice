/*
** EPITECH PROJECT, 2020
** Rom.h
** File description:
** Temp
*/

#pragma once
#include "AComponent.hpp"

class Rom : public nts::AComponent {
public:
    Rom(const std::string &name);
    ~Rom();
    nts::Tristate compute(std::size_t pin = 1) override;


};
