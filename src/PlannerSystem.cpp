#include "PlannerSystem.h"

void PlannerSystem::Update(World& world){
    EntityManager& entityManager = world.GetEntityManager();

    AgentComponent& agentComponent = world.GetAgentComponent();

    const auto& agents = agentComponent.GetEntities();

    for (Entity entity : agents){
        BuildPlan(entity, world);
    }
}

void PlannerSystem::BuildPlan(Entity entity, World& world){
    PlannerComponent& plannerComponent = world.GetPlannerComponent();

    NeedComponent& needComponent = world.GetNeedComponent();

    ObservationComponent& observationComponent = world.GetObservationComponent();

    Observation& observation = observationComponent.Get(entity);

    const auto& visibleEntities = observation.Get();

    Entity nearestBerry = INVALID_ENTITY;
    Position berryPosition;
    float nearestBerryDistance = 1e9;
    Entity nearestWater = INVALID_ENTITY;
    Position waterPosition;
    float nearestWaterDistance = 1e9;
    
    for (const auto& visible : visibleEntities){
        if (visible.visibleType == VisibleType::Berry){
            if (visible.dist < nearestBerryDistance){
                nearestBerry = visible.entity;
                berryPosition = visible.position;
                nearestBerryDistance = visible.dist;
            }
        }
        if (visible.visibleType == VisibleType::Water){
            if (visible.dist < nearestWaterDistance){
                nearestWater= visible.entity;
                waterPosition = visible.position;
                nearestWaterDistance = visible.dist;
            }
        }
    }

    Planner& planner = plannerComponent.Get(entity);

    Need& need = needComponent.Get(entity);

    planner.planner.clear();

    Plan plan;

    if (need.Hunger > 50){
        if (nearestBerry != INVALID_ENTITY){
            plan.action = ActionType::Eat;
            plan.Priority = 100;
            plan.TargetEntity = nearestBerry;
            plan.TargetPosition = berryPosition;
            planner.planner.push_back(plan);
            // plan
        }
    }if (need.Thirst > 50){
        if (nearestWater != INVALID_ENTITY){
            plan.action = ActionType::Drink;
            plan.Priority = 100;
            plan.TargetEntity = nearestWater;
            plan.TargetPosition = waterPosition;
            planner.planner.push_back(plan);
            // plan
        }
    }if (need.Energy < 10){
        plan.action = ActionType::Sleep;
        plan.Priority = 75;
        planner.planner.push_back(plan);
    }if (need.Energy > 10){
        plan.action = ActionType::Move;
        plan.Priority= 25;
        planner.planner.push_back(plan);
    }
}