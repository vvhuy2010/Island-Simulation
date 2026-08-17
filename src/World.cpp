#include "World.h"
#include "NeedSystem.h"
#include "ObservationSystem.h"
#include "PlannerSystem.h"
#include "DecisionSystem.h"
#include "MovementSystem.h"
#include "MemoryComponent.h"
#include "ActionSystem.h"
#include "MemorySystem.h"

#include <random>

uint64_t World::GetCurrentTick() const
{
    return currentTick;
}

SimulationTime World::GetCurrentTime() const
{
    uint64_t remainingTicks = currentTick;

    uint64_t day = remainingTicks / Time::TICKS_PER_DAY;
    remainingTicks %= Time::TICKS_PER_DAY;

    uint64_t hour = remainingTicks / Time::TICKS_PER_HOUR;
    remainingTicks %= Time::TICKS_PER_HOUR;

    uint64_t minute = remainingTicks / Time::TICKS_PER_MINUTE;
    remainingTicks %= Time::TICKS_PER_MINUTE;

    uint64_t second = remainingTicks / Time::TICKS_PER_SECOND;
    remainingTicks %= Time::TICKS_PER_SECOND;

    return {
        day,
        hour,
        minute,
        second,
        remainingTicks
    };
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

    NeedSystem needSystem;
    ObservationSystem observationSystem;
    PlannerSystem plannerSystem;
    DecisionSystem decisionSystem;
    ActionSystem actionSystem;
    MemorySystem memorySystem;

    needSystem.Update(*this);
    observationSystem.Update(*this);
    memorySystem.Update(*this);
    plannerSystem.Update(*this);
    decisionSystem.Update(*this);
    actionSystem.Update(*this);

    movementSystem.Update(*this);
    healthSystem.Update(*this);

    currentTick++;
}
PositionComponent& World::GetPositionComponent(){
    return positionComponent;
}

ActionComponent& World::GetActionComponent(){
    return actionComponent;
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
NeedComponent& World::GetNeedComponent(){
    return needComponent;
}
PlannerComponent& World::GetPlannerComponent(){
    return plannerComponent;
}
InventoryComponent& World::GetInventoryComponent(){
    return inventoryComponent;
}
MemoryComponent& World::GetMemoryComponent(){
    return memoryComponent;
}
Entity World::SpawnHuman(const std::string& name, Position position)
{
    Entity entity = CreateEntity();

    agentComponent.Add(entity, Agent{name});

    positionComponent.Add(entity, position);

    healthComponent.Add(entity, Health{});

    needComponent.Add(entity, Need{});

    inventoryComponent.Add(entity, Inventory{});

    plannerComponent.Add(entity, Planner{});

    actionComponent.Add(entity, Action{});

    memoryComponent.Add(entity, std::vector<Memory>{});

    plannerComponent.Add(entity, Planner{});

    observationComponent.Add(entity, Observation{});

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
