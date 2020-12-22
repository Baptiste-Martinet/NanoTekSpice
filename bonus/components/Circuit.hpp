/*
** EPITECH PROJECT, 2020
** nanotekspice
** File description:
** desc
*/

#pragma once
#include "../AComponent.hpp"
#include "../Factory.hpp"

#define NB_TEXTURES 2

enum texture_enum {
    BACKGROUND,
    CURSOR
};

typedef struct tools_s
{
    sf::VideoMode videoMode;
    sf::RenderWindow window;
    sf::Event event;
} tools_t;

typedef struct global_s
{
    tools_t tools;
    sf::Texture textures[NB_TEXTURES];
    sf::RectangleShape backgound;
} global_t;

class Circuit : public nts::AComponent
{
public:
    Circuit(const std::string &name);
    ~Circuit();
    nts::Tristate compute(std::size_t pin = 1) override;
    void addComponent(nts::IComponent *component);
    nts::IComponent *getComponentAt(size_t idx) const;
    void createFromFile(std::string const filepath);
    void createLinkFromString(std::string const line);
    nts::IComponent *getComponentByName(std::string const name) const;
    void dump() const override;
    void sortComponentsByName();
    void initInputsByArgs(int ac, char **av);
    void IOerrorGestion();
    bool setInputStateByString(std::string str, bool);
    void updateClocks();
    /* sfml */
    void initSfml();
    void gameLoop();
    void eventManager();
    void display();
private:
    std::vector<nts::IComponent *> _components;
    global_t _glob;
    nts::IComponent *_dragged;
    sf::Sprite _cursor;
    bool _isSimulating;
};

template <class Container>
void splitToArray(const std::string &str, Container &cont, const std::string &delims)
{
    size_t current = 0;
    size_t previous = 0;

    current = str.find_first_of(delims);
    while (current != std::string::npos) {
        cont.push_back(str.substr(previous, current - previous));
        previous = current + 1;
        current = str.find_first_of(delims, previous);
    }
    cont.push_back(str.substr(previous, current - previous));
}