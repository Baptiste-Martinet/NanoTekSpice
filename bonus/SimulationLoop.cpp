/*
** EPITECH PROJECT, 2020
** SimulationLoop.cpp
** File description:
** Temp
*/

#include <csignal>
#include <zconf.h>
#include "SimulationLoop.hpp"

int signum = 1;

SimulationLoop::SimulationLoop(Circuit *circuit)
{
    this->_circuit = circuit;
}

static void signalHandler1(int signal)
{
    signum = signal;
}

void SimulationLoop::loop(void)
{
    signum = 1;
    std::signal(SIGINT, signalHandler1);

    while (signum != SIGINT) {
        std::cout << "SIMULATING.........." << std::endl;
        this->_circuit->compute();
        sleep(1);
    }
}

void SimulationLoop::run(void)
{
    std::string str;
    
    std::cout << "> ";
    while(std::getline(std::cin, str)) {
        if (str == "exit") {
            break;
        } else if (str == "loop") {
            loop();
        } else if (str == "display") {
            this->_circuit->display();
        } else if (str == "dump") {
            this->_circuit->dump();
        } else if (str == "simulate") {
            this->_circuit->compute();
        } else if (this->_circuit->setInputStateByString(str, false)) {
            //nothing to do here
        } else {
            std::cout << "Unknown instruction. Please verify and try again." << std::endl;
        }
        std::cout << "> ";
    }
}
