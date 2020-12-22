/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** event
*/

#include "../components/Circuit.hpp"

void Circuit::eventManager()
{
    while (this->_glob.tools.window.pollEvent(this->_glob.tools.event)) {
        if (this->_glob.tools.event.type == sf::Event::Closed)
            this->_glob.tools.window.close();
        if (this->_glob.tools.event.type == sf::Event::KeyPressed) {
            if (this->_glob.tools.event.key.code == sf::Keyboard::Escape)
                this->_glob.tools.window.close();
            if (this->_glob.tools.event.key.code == sf::Keyboard::Q)
                this->_glob.tools.window.close();
            if (this->_glob.tools.event.key.code == sf::Keyboard::L)
                this->_isSimulating = !this->_isSimulating;
        }
        sf::FloatRect bounds;
        sf::Vector2f mousePos(sf::Mouse::getPosition(_glob.tools.window).x, sf::Mouse::getPosition(_glob.tools.window).y);
        if (this->_glob.tools.event.type == sf::Event::MouseMoved) {
            //todo
        }
        if (this->_glob.tools.event.type == sf::Event::MouseButtonPressed) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                if (!this->_dragged) {
                    for (nts::IComponent *component : this->_components) {
                        bounds = component->getRect().getGlobalBounds();
                        if (bounds.left < mousePos.x && mousePos.x < (bounds.left + bounds.width) &&
                            bounds.top < mousePos.y && mousePos.y < (bounds.top + bounds.height)) {
                            this->_dragged = component;
                            break;
                        }
                    }
                } else {
                    this->_dragged = nullptr;
                }
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                for (nts::IComponent *component : this->_components) {
                    if (component->getType() != "input")
                        continue;
                    bounds = component->getRect().getGlobalBounds();
                    if (bounds.left < mousePos.x && mousePos.x < (bounds.left + bounds.width) &&
                        bounds.top < mousePos.y && mousePos.y < (bounds.top + bounds.height)) {
                        component->getPin(1)->setState((component->getPin(1)->getState() == nts::TRUE ? nts::FALSE : nts::TRUE));
                        Circuit::compute(2);
                        break;
                    }
                }
            }
        }
    }
}
