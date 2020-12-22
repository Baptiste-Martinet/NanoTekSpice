/*
** EPITECH PROJECT, 2020
** TriStateGates.h
** File description:
** Temp
*/

#ifndef OOP_NANOTEKSPICE_2019_TRISTATEGATES_HPP
#define OOP_NANOTEKSPICE_2019_TRISTATEGATES_HPP

#include "IComponent.hpp"

namespace gate {
    nts::Tristate And(nts::Tristate a, nts::Tristate b);
    nts::Tristate NAnd(nts::Tristate a, nts::Tristate b);
    nts::Tristate Or(nts::Tristate a, nts::Tristate b);
    nts::Tristate Nor(nts::Tristate a, nts::Tristate b);
    nts::Tristate Xor(nts::Tristate a, nts::Tristate b);
    nts::Tristate XNor(nts::Tristate a, nts::Tristate b);
    nts::Tristate Not(nts::Tristate a);
}


#endif //OOP_NANOTEKSPICE_2019_TRISTATEGATES_HPP
