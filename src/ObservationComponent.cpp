// #pragma once

// #include "Observation.h"
#include "ObservationComponent.h"

void ObservationComponent::Add(Entity entity, Observation Observation){
    if (sparse.size() <= entity){
        sparse.resize(entity + 1, INVALID_INDEX);
    }

    size_t index = denseEntities.size();

    denseObservation.push_back({Observation});
    
    denseEntities.push_back(entity);

    sparse[entity] = index; // 0 index
}

bool ObservationComponent::Has(Entity entity){
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

Observation& ObservationComponent::Get(Entity entity)
{
    return denseObservation[sparse[entity]];
}

void ObservationComponent::Remove(Entity entity){
    if (!Has(entity)){
        return;
    }

    size_t index = sparse[entity];

    size_t last_index = denseObservation.size() - 1;

    denseEntities[index] = denseEntities[last_index];
    
    denseObservation[index] = denseObservation[last_index];

    sparse[denseEntities[index]] = index;

    denseEntities.pop_back();

    denseObservation.pop_back();

    sparse[entity] = INVALID_INDEX;
}
