#include "World.h"
#include "EntityManager.h"
#include "AgentComponent.h"
#include "ObservationSystem.h"
#include <random>

uint64_t World::GetCurrentTick() const
{
    return currentTick;
}


Entity World::CreateEntity(){
    return entityManager.Create();
}

void World::DestroyEntity(Entity entity){
    if (healthComponent.Has(entity))
    {
        healthComponent.Remove(entity);
    }

    if (positionComponent.Has(entity))
    {
        positionComponent.Remove(entity);
    }

    if (resourceComponent.Has(entity))
    {
        resourceComponent.Remove(entity);
    }

    if (agentComponent.Has(entity))
    {
        agentComponent.Remove(entity);
    }

    entityManager.Destroy(entity);
}

void World::Update(){
    healthSystem.Update(*this);

    movementSystem.Update(*this);

    ObservationSystem observationSystem;

    observationSystem.Update(*this);

    currentTick++;
}

PositionComponent& World::GetPositionComponent(){
    return positionComponent;
}

HealthComponent& World::GetHealthComponent(){
    return healthComponent;
}

ResourceComponent& World::GetResourceComponent(){
    return resourceComponent ;
}

AgentComponent& World::GetAgentComponent(){
    return agentComponent;
}

ObservationComponent& World::GetObservationComponent(){
    return observationComponent;
}
EntityManager& World::GetEntityManager(){
    return entityManager;
}
Entity World::SpawnHuman(const std::string& name, Position position){
    // World::CreateEntity();a
    // World world;
    Entity entity = CreateEntity();
    // CreateEntity();

    Agent agent;
    agent.name = name;

    agentComponent.Add(entity, agent);
    positionComponent.Add(entity, position);
    // world.GetPositionComponent().Add(name, position);
    Observation observation;
    // ObservationComponent observationComponent;
    observationComponent.Add(entity, observation);

    Health health;

    health.currentHealth = 100;
    health.maxHealth = 100;

    healthComponent.Add(entity, health);

    return entity;
}

Entity World::SpawnTree(Position position){
    Entity entity = CreateEntity();

    positionComponent.Add(entity, position);

    Resource resource;

    resource.type = ResourceType::Tree;

    resourceComponent.Add(entity, resource);

    return entity;
}

Entity World::SpawnBerry(Position position){
    Entity entity = CreateEntity();

    positionComponent.Add(entity, position);

    Resource resource;

    resource.type = ResourceType::Berry;

    resourceComponent.Add(entity, resource);

    return entity;
}

void World::GenerateWorld(){
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> positionDistribution(0, 999);

    for (int i = 0; i < 100; ++i){
        Position p;
        p.x = positionDistribution(gen);
        p.y = positionDistribution(gen); 
        SpawnTree(p);
    }

    for (int i = 0; i < 50; ++i){
        Position p;
        p.x = positionDistribution(gen);
        p.y = positionDistribution(gen);
        SpawnBerry(p);
    }

    std::vector<std::string> agentNames = {"Alice", "John", "Emma", "David"};

    for (int i = 0; i < 4; ++i){
        Position p;
        p.x = positionDistribution(gen);
        p.y = positionDistribution(gen);
        SpawnHuman(agentNames[i], p);
    }
}
