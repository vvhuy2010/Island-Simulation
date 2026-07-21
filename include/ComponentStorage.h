#pragma once

#include <vector>
#include "Entity.h"

template<typename T>
class ComponentStorage
{
protected:
    std::vector<T> dense;
    std::vector<Entity> denseEntities;
    std::vector<size_t> sparse;

public:
    void Add(Entity entity, const T& component)
    {
        if (sparse.size() <= entity)
        {
            sparse.resize(entity + 1, INVALID_INDEX);
        }

        size_t index = dense.size();

        dense.push_back(component);
        denseEntities.push_back(entity);

        sparse[entity] = index;
    }

    bool Has(Entity entity) const
    {
        return entity < sparse.size() &&
               sparse[entity] != INVALID_INDEX;
    }

    T& Get(Entity entity)
    {
        return dense[sparse[entity]];
    }

    void Remove(Entity entity)
    {
        if (!Has(entity))
            return;

        size_t index = sparse[entity];
        size_t last = dense.size() - 1;

        dense[index] = dense[last];
        denseEntities[index] = denseEntities[last];

        sparse[denseEntities[index]] = index;

        dense.pop_back();
        denseEntities.pop_back();

        sparse[entity] = INVALID_INDEX;
    }

    const std::vector<Entity>& GetEntities() const
    {
        return denseEntities;
    }
};