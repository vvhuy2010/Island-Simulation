#pragma once
#include "Entity.h"
class World;

class MemorySystem{

public:
    void Update(World& world);

private:
    void RememberObservation(Entity entity, World& world);
};