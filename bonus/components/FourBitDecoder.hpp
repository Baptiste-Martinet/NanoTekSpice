/*
** EPITECH PROJECT, 2020
** FourBitDecoder.h
** File description:
** Temp
*/

#pragma once
#include "AComponent.hpp"

class FourBitDecoder : public nts::AComponent {
public:
    FourBitDecoder(const std::string &name);
    ~FourBitDecoder();
    nts::Tristate compute(std::size_t pin = 1) override;


};
