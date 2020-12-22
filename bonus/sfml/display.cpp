/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** display
*/

#include "../components/Circuit.hpp"

void Circuit::display()
{
    sf::Vector2f mousePos = (sf::Vector2f)sf::Mouse::getPosition(_glob.tools.window);
    if (this->_dragged != nullptr) {
        this->_dragged->getRect().setPosition(mousePos - sf::Vector2f(50,50));
    }
    for (float y = 0; y < _glob.tools.window.getSize().y; y += 100) {
        for (float x = 0; x < _glob.tools.window.getSize().x; x += 100) {
            this->_glob.backgound.setPosition(sf::Vector2f(x, y));
            this->_glob.tools.window.draw(this->_glob.backgound);
        }
    }
    for (nts::IComponent *component : this->_components) {
        component->displayPin(this->_glob.tools.window);
        this->_glob.tools.window.draw(component->getRect());

        sf::Text text = component->getText();
        if (text.getString() != "Null") {
            text.setPosition(component->getRect().getPosition() + sf::Vector2f(3, 3));
            this->_glob.tools.window.draw(text);
        }
    }
    this->_cursor.setPosition(mousePos - sf::Vector2f(0, 40));
    this->_glob.tools.window.draw(this->_cursor);
}