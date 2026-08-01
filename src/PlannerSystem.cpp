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

    Planner& planner = plannerComponent.Get(entity);

    Need& need = needComponent.Get(entity);

    planner.planner.clear();

    Plan plan;

    if (need.Hunger > 50){
        plan.action = ActionType::Eat;
        plan.Priority = 100;
        planner.planner.push_back(plan);
    }if (need.Thirst > 50){
        plan.action = ActionType::Drink;
        plan.Priority = 80;
        planner.planner.push_back(plan);
    }if (need.Energy < 10){
        plan.action = ActionType::Sleep;
        plan.Priority = 75;
        planner.planner.push_back(plan);
    }else{
        plan.action = ActionType::Move;
        plan.Priority= 25;
        planner.planner.push_back(plan);
    }
}