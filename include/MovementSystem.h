#pragma once

#include "Entity.h"
#include <vector>
#include "Position.h"
// #include "World.h"

class World;

class MovementSystem{

public:
    void Update(World& world);
};
