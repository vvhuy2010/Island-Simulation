#pragma once

#include "Entity.h"
#include <vector>
#include "Position.h"
#include "Health.h"

class HealthComponent
{
public:
    void Add(Entity entity, Health Health);

    void Remove(Entity entity);

    Health& Get(Entity entity);
    
    bool Has(Entity entity);

private:
    // Entity entity;
    // std::vector<float> x;
    std::vector<Health> denseHealth;
    std::vector<size_t> sparse;
    std::vector<Entity> denseEntities;
};
