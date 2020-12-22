/*
** EPITECH PROJECT, 2020
** name
** File description:
** desc
*/

#pragma once
#include "IComponent.hpp"
#include "TriStateGates.hpp"

namespace nts {
    class AComponent : public IComponent {
    public:
        AComponent(const std::string &name);
        virtual ~AComponent();
        //seters
        void setLink(std::size_t pin, nts::IComponent *other, std::size_t otherPin);
        //geters
        nts::Pin *getPin(size_t indxPin) const;
        size_t getPinIndx(nts::Pin *pin) const;
        std::string getName() const;
        size_t getNbPins() const;
        //others
        void dump() const;
        void setName(const std::string &newName);
    protected:
        std::string _name;
        std::vector<nts::Pin *> _pins;
    };
};