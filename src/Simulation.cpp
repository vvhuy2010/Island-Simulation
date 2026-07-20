#include "Simulation.h"
#include <iostream>

void Simulation::Run()
{
    while (running){
        // add sau;
        world.Update();
        std::cout << world.GetCurrentTick() << "\n";
        // running = false;

        if(world.GetCurrentTick() == 10){
            running = false;
        }
    }
}