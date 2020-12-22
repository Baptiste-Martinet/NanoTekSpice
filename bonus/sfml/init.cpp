/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** init
*/

#include "../components/Circuit.hpp"

void createRectangle(sf::RectangleShape &rectangle, sf::Vector2f pos, sf::Vector2f size, sf::Color color, float thickness, sf::Color thickColor, sf::Texture *texture)
{
    rectangle.setPosition(pos);
    rectangle.setSize(size);
    rectangle.setFillColor(color);
    rectangle.setOutlineThickness(thickness);
    rectangle.setOutlineColor(thickColor);
    rectangle.setTexture(texture, true);
}

void initTextures(global_t &glob)
{
    if (!glob.textures[BACKGROUND].loadFromFile("textures/32/sandstone_top.png"))
        exit(84);
    if (!glob.textures[CURSOR].loadFromFile("textures/32/carrot.png"))
        exit(84);
}

void Circuit::initSfml()
{
    this->_glob.tools.videoMode = (sf::VideoMode) {1536, 864};
    this->_glob.tools.window.create(this->_glob.tools.videoMode, "Redstone simulator (MB1 to interact, MB2 to drag components & 'L' to start looping)");
    this->_glob.tools.window.setPosition((sf::Vector2i){160, 80});
    this->_glob.tools.window.setMouseCursorVisible(false);
    initTextures(this->_glob);
    this->_cursor = sf::Sprite(this->_glob.textures[CURSOR]);
    this->_cursor.setScale(2.f,2.f);
    createRectangle(this->_glob.backgound, (sf::Vector2f){0, 0}, (sf::Vector2f){100, 100}, (sf::Color){255,255,255}, 0, (sf::Color){0,0,0,0}, &this->_glob.textures[BACKGROUND]);
}