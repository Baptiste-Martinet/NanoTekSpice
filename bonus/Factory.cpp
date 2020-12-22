/*
** EPITECH PROJECT, 2020
** name
** File description:
** desc
*/

#include "Factory.hpp"

nts::Factory::Factory()
{
}

nts::Factory::~Factory()
{
}

nts::IComponent *nts::Factory::createComponent(const std::string &type ,const std::string &value, sf::Vector2f pos)
{
    static std::vector<std::string> names;

    for (std::string name : names) {
        if (value == name) {
            throw Error("Can't create component. Reason: Component's name is already taken");
            return nullptr;
        }
    }
    names.push_back(value);
    
    if (type == "4011")
        return (Factory::create4011(value, pos));
    if (type == "input")
        return (Factory::createInput(value, pos));
    if (type == "output")
        return (Factory::createOutput(value, pos));
    if (type == "true")
        return (Factory::createTrue(value, pos));
    if (type == "false")
        return (Factory::createFalse(value, pos));
    if (type == "clock")
        return (Factory::createClock(value, pos));
    if (type == "4001")
        return (Factory::create4001(value, pos));
    if (type == "4008")
        return (Factory::create4008(value, pos));
    if (type == "4013")
        return (Factory::create4013(value, pos));
    if (type == "4017")
        return (Factory::create4017(value, pos));
    if (type == "4030")
        return (Factory::create4030(value, pos));
    if (type == "4069")
        return (Factory::create4069(value, pos));
    if (type == "4071")
        return (Factory::create4071(value, pos));
    if (type == "4081")
        return (Factory::create4081(value, pos));
    if (type == "4094")
        return (Factory::create4094(value, pos));
    if (type == "4514")
        return (Factory::create4514(value, pos));
    if (type == "4801")
        return (Factory::create4801(value, pos));
    if (type == "2716")
        return (Factory::create2716(value, pos));
    throw Error("Can't create component. Reason: Unknown component type: " + type);
    return nullptr;
}

nts::IComponent *nts::Factory::create4011(const std::string &value, sf::Vector2f pos) const noexcept
{
    return (new FourNandGates(value, pos));
}

nts::IComponent *nts::Factory::createInput(const std::string &value, sf::Vector2f pos) const noexcept
{
    return (new Input(value, pos));
}

nts::IComponent *nts::Factory::createOutput(const std::string &value, sf::Vector2f pos) const noexcept
{
    return (new Output(value, pos));
}

nts::IComponent *nts::Factory::createTrue(const std::string &value, sf::Vector2f pos) const noexcept
{
    return (new True(value, pos));
}

nts::IComponent *nts::Factory::createFalse(const std::string &value, sf::Vector2f pos) const noexcept
{
    return (new False(value, pos));
}

nts::IComponent *nts::Factory::createClock(const std::string &value, sf::Vector2f pos) const noexcept
{
    return (new Clock(value, pos));
}

nts::IComponent *nts::Factory::create4001(const std::string &value, sf::Vector2f pos) const noexcept
{
    return (new FourNorGates(value, pos));
}

nts::IComponent *nts::Factory::create4008(const std::string &value, sf::Vector2f pos) const noexcept
{
    return (new FourBitAdder(value, pos));
}

nts::IComponent *nts::Factory::create4013(const std::string &value, sf::Vector2f pos) const noexcept
{
    return (new DualFlipFlop(value, pos));
}

nts::IComponent *nts::Factory::create4017(const std::string &value, sf::Vector2f pos) const noexcept
{
    (void)pos;
    return (new TenBitJohnsonDecade(value));
}

nts::IComponent *nts::Factory::create4030(const std::string &value, sf::Vector2f pos) const noexcept
{
    return (new FourXorGates(value, pos));
}

nts::IComponent *nts::Factory::create4040(const std::string &value, sf::Vector2f pos) const noexcept
{
    (void)pos;
    return (new TwelveBitCounter(value));
}

nts::IComponent *nts::Factory::create4069(const std::string &value, sf::Vector2f pos) const noexcept
{
    return (new SixInverterGates(value, pos));
}

nts::IComponent *nts::Factory::create4071(const std::string &value, sf::Vector2f pos) const noexcept
{
    return (new FourOrGates(value, pos));
}

nts::IComponent *nts::Factory::create4081(const std::string &value, sf::Vector2f pos) const noexcept
{
    return (new FourAndGates(value, pos));
}

nts::IComponent *nts::Factory::create4094(const std::string &value, sf::Vector2f pos) const noexcept
{
    (void)pos;
    return (new EightBitShiftRegister(value));
}

nts::IComponent *nts::Factory::create4514(const std::string &value, sf::Vector2f pos) const noexcept
{
    (void)pos;
    return (new FourBitDecoder(value));
}

nts::IComponent *nts::Factory::create4801(const std::string &value, sf::Vector2f pos) const noexcept
{
    (void)pos;
    return (new Ram(value));
}

nts::IComponent *nts::Factory::create2716(const std::string &value, sf::Vector2f pos) const noexcept
{
    (void)pos;
    return (new Rom(value));
}