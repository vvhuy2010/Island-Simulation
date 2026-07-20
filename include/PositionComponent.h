#pragma once

#include "Entity.h"
#include <bits/stdc++.h>
#include "Position.h"


class PositionComponent
{
public:
    void Add(Entity entity, Position position);
    
    void Remove(Entity entity);

    Position& Get(Entity entity);

    bool Has(Entity entity);

private:
    // Entity entity;
    // std::vector<float> x;
    std::vector<Position> densePositions;
    std::vector<size_t> sparse;
    std::vector<Entity> denseEntities;
};