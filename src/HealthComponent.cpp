// #pragma once

#include "HealthComponent.h"
#include "HealthSystem.h"

void HealthComponent::Add(Entity entity, Health health){
    if (sparse.size() <= entity){
        sparse.resize(entity + 1, INVALID_INDEX);
    }

    size_t index = denseEntities.size();

    denseHealth.push_back({health});
    
    denseEntities.push_back(entity);

    sparse[entity] = index; // 0 index
}

bool HealthComponent::Has(Entity entity){
    if (entity >= sparse.size()){
        return false;
    }
    else if (sparse[entity] == INVALID_INDEX){
        return false;
    }
    else{
        return true;
    }
}

Health& HealthComponent::Get(Entity entity)
{
    return denseHealth[sparse[entity]];
}

void HealthComponent::Remove(Entity entity){
    if (!Has(entity)){
        return;
    }

    size_t index = sparse[entity];

    size_t last_index = denseHealth.size() - 1;

    denseEntities[index] = denseEntities[last_index];
    
    denseHealth[index] = denseHealth[last_index];

    sparse[denseEntities[index]] = index;

    denseEntities.pop_back();

    denseHealth.pop_back();

    sparse[entity] = INVALID_INDEX;
}