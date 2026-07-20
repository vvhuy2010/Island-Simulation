#pragma once

#include "VisibleEntity.h"
#include <vector>
#include "Observation.h"
// #include "Observation.h"

class ObservationComponent
{
public:
    void Add(Entity entity, Observation Observation);

    void Remove(Entity entity);

    Observation& Get(Entity entity);
    
    bool Has(Entity entity);

private:
    // Entity entity;
    // std::vector<float> x;
    std::vector<Observation> denseObservation;
    std::vector<size_t> sparse;
    std::vector<Entity> denseEntities;
};
