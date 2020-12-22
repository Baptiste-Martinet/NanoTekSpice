/*
** EPITECH PROJECT, 2020
** TwelveBitCounter.h
** File description:
** Temp
*/

#pragma once
#include "AComponent.hpp"

class TwelveBitCounter : public nts::AComponent {
public:
    TwelveBitCounter(const std::string &name);
    ~TwelveBitCounter();
    nts::Tristate compute(std::size_t pin = 1) override;

};
