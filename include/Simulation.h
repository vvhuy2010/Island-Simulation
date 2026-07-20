#pragma once

#include "Entity.h"
#include "World.h"

class Simulation{

public:
    // void Constuctor();
    void Run();

private:
    World world;
    bool running = true;
};