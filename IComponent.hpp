/*
** EPITECH PROJECT, 2020
** IComponent.h
** File description:
** Temp
*/

#ifndef OOP_NANOTEKSPICE_2019_ICOMPONENT_HPP
#define OOP_NANOTEKSPICE_2019_ICOMPONENT_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <string>
#include <regex>
#include <tuple>
#include <algorithm>
#include "Error.hpp"

namespace nts {
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class IComponent;

    class Pin {
    public:
        Pin(nts::IComponent *component, const std::string &type, nts::Tristate state = nts::Tristate::UNDEFINED);
        ~Pin();
        //setters
        void setState(nts::Tristate state);
        //getters
        nts::Tristate getState();
        nts::Tristate getStateNoCompute() const;
        std::string getType() const;
        std::vector<std::tuple<size_t, std::string>> getLinksIndexes() const;
        nts::IComponent *getComponent() const;
        size_t getNbLinks() const;
        //others
        void addLink(Pin *otherPin);
    private:
        nts::Tristate _state;
        std::vector<Pin *> _links;
        nts::IComponent *_component;
        std::string _type;
    };

    class IComponent {
    public :
        virtual ~IComponent() = default;

    public :
        //seters
        virtual void setLink(std::size_t Pin, nts::IComponent *other, std::
        size_t otherPin) = 0;
        virtual void setName(const std::string &newName) = 0;
        //geters
        virtual nts::Pin *getPin(size_t indxPin) const = 0;
        virtual size_t getPinIndx(nts::Pin *pin) const = 0;
        virtual size_t getNbPins() const = 0;
        virtual std::string getName() const = 0;
        //others
        virtual nts::Tristate compute(std::size_t Pin = 1) = 0;
        virtual void dump() const = 0;
    };
}

#endif //OOP_NANOTEKSPICE_2019_ICOMPONENT_HPP
