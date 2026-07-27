#pragma once

#include "Entity.h"

#include <vector>
#include <stack>

class EntityManager
{
public:
    Entity Create();
    void Destroy(Entity entity);

    bool Has(Entity entity);

    const std::vector<Entity>& GetAllEntities();

private:
    Entity nextEntity = 0;
    std::stack<Entity> freeEntities;
    std::vector<Entity> aliveEntities;
    std::vector<size_t> aliveIndex;
};