#include "Entity.h"
#include "Position.h"
#include "PositionComponent.h"

void PositionComponent::Add(Entity entity, Position position){
    if (sparse.size() <= entity){
        sparse.resize(entity + 1, INVALID_INDEX);
    }

    size_t index = denseEntities.size();

    densePositions.push_back({position.x, position.y});
    
    denseEntities.push_back(entity);

    sparse[entity] = index; // 0 index
}

bool PositionComponent::Has(Entity entity){
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

Position& PositionComponent::Get(Entity entity)
{
    return densePositions[sparse[entity]];
}

void PositionComponent::Remove(Entity entity){
    if (!Has(entity)){
        return;
    }

    size_t index = sparse[entity];

    size_t last_index = densePositions.size() - 1;

    denseEntities[index] = denseEntities[last_index];
    
    densePositions[index] = densePositions[last_index];

    sparse[denseEntities[index]] = index;

    denseEntities.pop_back();

    densePositions.pop_back();

    sparse[entity] = INVALID_INDEX;
}