/*
** EPITECH PROJECT, 2020
** SimulationLoop.h
** File description:
** Temp
*/

#ifndef OOP_NANOTEKSPICE_2019_SIMULATIONLOOP_HPP
#define OOP_NANOTEKSPICE_2019_SIMULATIONLOOP_HPP

#include <string>
#include <iostream>
#include "components/Circuit.hpp"

class SimulationLoop {
public:
    SimulationLoop(Circuit *circuit);
    void run(void);

private:
    int magic = 42;
    Circuit *_circuit;
    void loop(void);
    void signalHandler(int signal);
};


#endif //OOP_NANOTEKSPICE_2019_SIMULATIONLOOP_HPP
