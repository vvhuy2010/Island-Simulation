#pragma once

#include "Entity.h"
#include <vector>
#include "Position.h"
#include "HealthComponent.h"

class World;

class HealthSystem
{
public:
    void Update(World& world);
private:
    // Entity entity;
    // std::vector<float> x;
};
