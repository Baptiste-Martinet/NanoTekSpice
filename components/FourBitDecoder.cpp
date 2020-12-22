/*
** EPITECH PROJECT, 2020
** FourBitDecoder.cpp
** File description:
** Temp
*/

#include "FourBitDecoder.hpp"

FourBitDecoder::FourBitDecoder(const std::string &name) : AComponent(name) {

}

FourBitDecoder::~FourBitDecoder() {

}

nts::Tristate FourBitDecoder::compute(std::size_t pin) {
    (void)pin;
    return nts::UNDEFINED;
}
