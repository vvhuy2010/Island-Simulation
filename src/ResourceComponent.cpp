#include "Entity.h"
#include "Resource.h"
#include "ResourceComponent.h"

void ResourceComponent::Add(Entity entity, Resource resource){
    if (sparse.size() <= entity){
        sparse.resize(entity + 1, INVALID_INDEX);
    }

    size_t index = denseEntities.size();

    denseResources.push_back(resource);
    
    denseEntities.push_back(entity);

    sparse[entity] = index; // 0 index
}

bool ResourceComponent::Has(Entity entity){
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

Resource& ResourceComponent::Get(Entity entity)
{
    return denseResources[sparse[entity]];
}

void ResourceComponent::Remove(Entity entity){
    if (!Has(entity)){
        return;
    }

    size_t index = sparse[entity];

    size_t last_index = denseResources.size() - 1;

    denseEntities[index] = denseEntities[last_index];
    
    denseResources[index] = denseResources[last_index];

    sparse[denseEntities[index]] = index;

    denseEntities.pop_back();

    denseResources.pop_back();

    sparse[entity] = INVALID_INDEX;
}