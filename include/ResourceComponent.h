#pragma once

#include "Entity.h"
#include <bits/stdc++.h>
#include "Resource.h"


class ResourceComponent
{
public:
    void Add(Entity entity, Resource resource);
    
    void Remove(Entity entity);

    Resource& Get(Entity entity);

    bool Has(Entity entity);

private:
    // Entity entity;
    // std::vector<float> x;
    std::vector<Resource> denseResources;
    std::vector<size_t> sparse;
    std::vector<Entity> denseEntities;
};