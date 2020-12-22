/*
** EPITECH PROJECT, 2020
** name
** File description:
** desc
*/

#pragma once
#include "IComponent.hpp"
#include "components/Circuit.hpp"
#include "components/FourNandGates.hpp"
#include "components/Input.hpp"
#include "components/Output.hpp"
#include "components/True.hpp"
#include "components/False.hpp"
#include "components/Clock.hpp"
#include "components/FourNorGates.hpp"
#include "components/FourBitAdder.hpp"
#include "components/DualFlipFlop.hpp"
#include "components/TenBitJohnsonDecade.hpp"
#include "components/FourXorGates.hpp"
#include "components/TwelveBitCounter.hpp"
#include "components/SixInverterGates.hpp"
#include "components/FourOrGates.hpp"
#include "components/FourAndGates.hpp"
#include "components/EightBitShiftRegister.hpp"
#include "components/FourBitDecoder.hpp"
#include "components/Ram.hpp"
#include "components/Rom.hpp"
#include "components/Terminal.hpp"

namespace nts {
    class Factory {
    public:
        Factory();
        ~Factory();
        nts::IComponent *createComponent(const std::string &type ,const std::string &value);
    private:
        nts::IComponent *create4011(const std::string &value) const noexcept;
        nts::IComponent *createInput(const std::string &value) const noexcept;
        nts::IComponent *createOutput(const std::string &value) const noexcept;
        nts::IComponent *createTrue(const std::string &value) const noexcept;
        nts::IComponent *createFalse(const std::string &value) const noexcept;
        nts::IComponent *createClock(const std::string &value) const noexcept;
        nts::IComponent *create4001(const std::string &value) const noexcept;
        nts::IComponent *create4008(const std::string &value) const noexcept;
        nts::IComponent *create4013(const std::string &value) const noexcept;
        nts::IComponent *create4017(const std::string &value) const noexcept;
        nts::IComponent *create4030(const std::string &value) const noexcept;
        nts::IComponent *create4040(const std::string &value) const noexcept;
        nts::IComponent *create4069(const std::string &value) const noexcept;
        nts::IComponent *create4071(const std::string &value) const noexcept;
        nts::IComponent *create4081(const std::string &value) const noexcept;
        nts::IComponent *create4094(const std::string &value) const noexcept;
        nts::IComponent *create4514(const std::string &value) const noexcept;
        nts::IComponent *create4801(const std::string &value) const noexcept;
        nts::IComponent *create2716(const std::string &value) const noexcept;
        nts::IComponent *createTerminal(const std::string &value) const noexcept;
    };
};