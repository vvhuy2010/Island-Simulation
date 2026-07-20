#pragma once

#include "Entity.h"
#include <bits/stdc++.h>
class EntityManager
{
public:
    Entity Create();
    void Destroy(Entity entity);
    // void Add(Entity entity);

    // void Remove(Entity entity);

    // Health& Get(Entity entity);
    
    bool Has(Entity entity);

    const std::vector<Entity>& GetAllEntities();
private:
    Entity nextEntity = 0;
    std::stack<Entity> freeEntities;
    std::vector<Entity> aliveEntities;
    std::vector<size_t> aliveIndex;
    // std::vector<bool> checkDestroy;
};