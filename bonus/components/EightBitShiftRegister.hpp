/*
** EPITECH PROJECT, 2020
** EightBitShiftRegister.h
** File description:
** Temp
*/

#pragma once
#include "AComponent.hpp"

class EightBitShiftRegister : public nts::AComponent {
public:
    EightBitShiftRegister(const std::string &name);
    ~EightBitShiftRegister();
    nts::Tristate compute(std::size_t pin = 1) override;


};
