#include "AgentComponent.h"

void AgentComponent::Add(Entity entity, Agent agent){
    if (sparse.size() <= entity){
        sparse.resize(entity + 1, INVALID_INDEX);
    }

    size_t index = denseEntities.size();

    denseAgents.push_back(agent);
    
    denseEntities.push_back(entity);

    sparse[entity] = index; // 0 index
}

bool AgentComponent::Has(Entity entity){
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

Agent& AgentComponent::Get(Entity entity)
{
    return denseAgents[sparse[entity]];
}

void AgentComponent::Remove(Entity entity){
    if (!Has(entity)){
        return;
    }

    size_t index = sparse[entity];

    size_t last_index = denseAgents.size() - 1;

    denseEntities[index] = denseEntities[last_index];
    
    denseAgents[index] = denseAgents[last_index];

    sparse[denseEntities[index]] = index;

    denseEntities.pop_back();

    denseAgents.pop_back();

    sparse[entity] = INVALID_INDEX;
}