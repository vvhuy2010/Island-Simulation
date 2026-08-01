#include "DecisionSystem.h"

void DecisionSystem::Decide(Entity entity, World& world){
    PlannerComponent& plannerComponent = world.GetPlannerComponent();
    Planner& planner = plannerComponent.Get(entity);
    ActionComponent& actionComponent = world.GetActionComponent();
    Action& action = actionComponent.Get(entity);
    Plan plan;
    // Action action;

    if (planner.planner.empty()){
        action.type = ActionType::Idle;
        // actionComponent.Add(entity, action);
        return;
    }
    float priorityMax = -1;
    const Plan* bestPlan = nullptr;

    for (const auto& entityPlan : planner.planner){
        if (entityPlan.Priority > priorityMax){
            priorityMax = entityPlan.Priority;
            // plan.action = entityPlan.action;
            bestPlan = &entityPlan;
        }
    }

    if (bestPlan != nullptr)
    {
        action.type = bestPlan->action;
    }

    // actionComponent.Add(entity, action);
}

void DecisionSystem::Update(World& world){
    EntityManager& em = world.GetEntityManager();
    const auto& entities = em.GetAllEntities();
    AgentComponent& ag = world.GetAgentComponent();
    ActionComponent& ne = world.GetActionComponent();
    // AgentComponent& ag = world.GetAgentComponent();

    const auto& agents = ag.GetEntities();
    for (Entity target: agents){
        // if (!ag.Has(entities[target])){
        //     continue;
        // }

        Decide(target, world);
    }
}