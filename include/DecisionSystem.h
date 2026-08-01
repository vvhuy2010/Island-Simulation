#pragma once

#include "World.h"

class DecisionSystem{

public:
    void Update(World& world);

private:
    void Decide(Entity entity, World& world);
};