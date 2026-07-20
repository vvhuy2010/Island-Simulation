#include "VelocityComponent.h"

void VelocityComponent::Add(Entity entity, Velocity velocity){
    if (sparse.size() <= entity){
        sparse.resize(entity + 1, INVALID_INDEX);
    }

    size_t index = denseEntities.size();

    denseVelocities.push_back(velocity);
    
    denseEntities.push_back(entity);

    sparse[entity] = index; // 0 index
}

bool VelocityComponent::Has(Entity entity){
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

Velocity& VelocityComponent::Get(Entity entity)
{
    return denseVelocities[sparse[entity]];
}

void VelocityComponent::Remove(Entity entity){
    if (!Has(entity)){
        return;
    }

    size_t index = sparse[entity];

    size_t last_index = denseVelocities.size() - 1;

    denseEntities[index] = denseEntities[last_index];
    
    denseVelocities[index] = denseVelocities[last_index];

    sparse[denseEntities[index]] = index;

    denseEntities.pop_back();

    denseVelocities.pop_back();

    sparse[entity] = INVALID_INDEX;
}