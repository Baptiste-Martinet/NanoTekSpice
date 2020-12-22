/*
** EPITECH PROJECT, 2020
** main.cpp
** File description:
** Temp
*/

#include "components/Circuit.hpp"

int main(int ac, char **av)
{
    Circuit *circuit = new Circuit("Michel le circuit electronique");
    global_t glob;

    if (ac < 2) {
        std::cerr << "nanotekspice: Usage: ./nanotekspice file [input_name=input_value...]" << std::endl;
        return (84);
    }
    try {
        circuit->createFromFile(av[1]);
        circuit->initInputsByArgs(ac, av);
        circuit->compute();
        circuit->initSfml();
        circuit->gameLoop();
    } catch (Error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return (84);
    }
    return 0;
}