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
#include <stdio.h>
#include <stdint.h>

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

    uint64_t GetCurrentTick() const;

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

    // PositionComponent& position();

    HealthComponent healthComponent;

    MovementSystem movementSystem;

    HealthSystem healthSystem;

    VelocityComponent velocityComponent;

    // VelocityComponent& velocity();

    ResourceComponent resourceComponent;

    AgentComponent agentComponent;

    // ResourceComponent& resource();

    ObservationComponent observationComponent;

    uint64_t currentTick = 0;
    // int GetCurrentTick();
};