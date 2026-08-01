#pragma once

#include "World.h"
#include "PlannerComponent.h"

class PlannerSystem{
    
public:
    void Update(World& world);

private:
    void BuildPlan(Entity entity, World& world);
};