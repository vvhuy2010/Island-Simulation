#pragma once

#include "Agent.h"
#include "Entity.h"
#include <vector>

class AgentComponent{

public:
    void Add(Entity entity, Agent agent);
    
    void Remove(Entity entity);

    Agent& Get(Entity entity);

    bool Has(Entity entity);

private:
    std::vector<Agent> denseAgents;
    std::vector<Entity> denseEntities;
    std::vector<size_t> sparse;
};