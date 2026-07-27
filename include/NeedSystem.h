#pragma once

#include "Need.h"
#include "NeedComponent.h"
#include "World.h"

class World;

class NeedSystem{

public:
    void Update(World& world);
    void Clamp(Need& need);
    void UpdateNeed(Entity entity, World& world);
    float Limit(float fl);
};