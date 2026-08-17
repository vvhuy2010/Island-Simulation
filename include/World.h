#pragma once

#include "EntityManager.h"
#include <iostream>
#include <string>
#include "PositionComponent.h"
#include "Health.h"
#include "MovementSystem.h"
#include "HealthSystem.h"
// #include "Simulation.h"
#include "VelocityComponent.h"
#include "ResourceComponent.h"
#include "ObservationComponent.h"
#include "AgentComponent.h"
// #include <cstdint>
#include "Time.h"
#include <stdio.h>
#include <stdint.h>
#include "NeedComponent.h"
#include "InventoryComponent.h"
#include "ActionComponent.h"
#include "PlannerComponent.h"
#include "MemoryComponent.h"

class World{

public:
    Entity CreateEntity();
    void DestroyEntity(Entity entity);
    void GenerateWorld();
    
    void Update();

    PositionComponent& GetPositionComponent();
    HealthComponent& GetHealthComponent();
    ResourceComponent& GetResourceComponent();
    AgentComponent& GetAgentComponent();
    ObservationComponent& GetObservationComponent();
    EntityManager& GetEntityManager();
    NeedComponent& GetNeedComponent();
    ActionComponent& GetActionComponent();
    InventoryComponent& GetInventoryComponent();
    PlannerComponent& GetPlannerComponent();
    MemoryComponent& GetMemoryComponent();

    // uint64_t GetCurrentTick() const;
    uint64_t GetCurrentTick() const;
    SimulationTime GetCurrentTime() const;

    //Enity;

    Entity SpawnHuman(
        const std::string& name,
        Position position
    );

    Entity SpawnTree(
        Position position
    );

    Entity SpawnBerry(
        Position position
    );
private:
    EntityManager entityManager;

    PositionComponent positionComponent;
    HealthComponent healthComponent;
    VelocityComponent velocityComponent;
    ResourceComponent resourceComponent;
    AgentComponent agentComponent;
    ObservationComponent observationComponent;
    InventoryComponent inventoryComponent;
    NeedComponent needComponent;
    ActionComponent actionComponent;
    PlannerComponent plannerComponent;
    MemoryComponent memoryComponent;

    MovementSystem movementSystem;
    HealthSystem healthSystem;

    uint64_t currentTick = 0;
};