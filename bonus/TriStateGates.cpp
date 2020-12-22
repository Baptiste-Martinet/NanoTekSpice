/*
** EPITECH PROJECT, 2020
** TriStateGates.cpp
** File description:
** Temp
*/

#include "TriStateGates.hpp"

nts::Tristate gate::Not(nts::Tristate a) {
    if (a == nts::UNDEFINED)
        return (nts::UNDEFINED);
    return (a == nts::TRUE ? nts::FALSE : nts::TRUE);
}

nts::Tristate gate::And(nts::Tristate a, nts::Tristate b) {
    if (a == nts::UNDEFINED || b == nts::UNDEFINED)
        return ((a == nts::FALSE || b == nts::FALSE) ? nts::FALSE : nts::UNDEFINED);
    return (a == b ? a : nts::FALSE);
}

nts::Tristate gate::NAnd(nts::Tristate a, nts::Tristate b) {
    return (gate::Not(And(a, b)));
}

nts::Tristate gate::Or(nts::Tristate a, nts::Tristate b) {
    if (a == nts::UNDEFINED || b == nts::UNDEFINED)
        return ((a == nts::TRUE || b == nts::TRUE)? nts::TRUE : nts::UNDEFINED);
    return (a == nts::TRUE ? a : b);
}

nts::Tristate gate::Nor(nts::Tristate a, nts::Tristate b) {
    return (gate::Not(Or(a, b)));
}

nts::Tristate gate::Xor(nts::Tristate a, nts::Tristate b) {
    if (a == nts::UNDEFINED || b == nts::UNDEFINED)
        return (nts::UNDEFINED);
    return (a != b ? nts::TRUE : nts::FALSE);
}

nts::Tristate gate::XNor(nts::Tristate a, nts::Tristate b) {
    return (gate::Not(Xor(a, b)));
}
