/*
** EPITECH PROJECT, 2020
** TenBitJohnsonDecade.h
** File description:
** Temp
*/

#pragma once
#include "AComponent.hpp"

class TenBitJohnsonDecade : public nts::AComponent {
public:
    TenBitJohnsonDecade(const std::string &name);
    ~TenBitJohnsonDecade();
    nts::Tristate compute(std::size_t pin = 1) override;
};
