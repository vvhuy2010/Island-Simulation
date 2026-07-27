#pragma once

#include "Action.h"
#include <vector>
#include "World.h"
#include "ActionComponent.h"

// class World;

class ActionSystem
{
public:
    void Update(World& world);
    void ExecuteAction(Entity entity, World& world);
    void FinishAction(Entity entity, World& world);
private:
    // Entity entity;
    // std::vector<float> x;
};
