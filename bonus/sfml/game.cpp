/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** game
*/

#include "../components/Circuit.hpp"

void Circuit::gameLoop()
{
    sf::Clock clock;

    while (this->_glob.tools.window.isOpen()) {
        Circuit::eventManager();
        if (this->_isSimulating && clock.getElapsedTime().asSeconds() > 1.f) {
            clock.restart();
            Circuit::compute();
        }
        this->_glob.tools.window.clear();
        Circuit::display();
        this->_glob.tools.window.display();
    }
}