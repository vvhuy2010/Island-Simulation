#include "ActionSystem.h"
#include "World.h"
#include "NeedSystem.h"
#include "InventorySystem.h"

void ActionSystem::ExecuteAction(Entity entity, World& world){
    ActionComponent& actionComponent = world.GetActionComponent();
    ResourceComponent& resourceComponent = world.GetResourceComponent();
    
    NeedComponent& needComponent = world.GetNeedComponent();
    Need& need = needComponent.Get(entity);
    NeedSystem needSystem;

    InventoryComponent& inventoryComponent = world.GetInventoryComponent();
    InventorySystem inventorySystem;
    // Inventory inventory;
    Inventory& inventory = inventoryComponent.Get(entity);

    Action& action = actionComponent.Get(entity);

    switch (action.type)
    {
        case ActionType::Idle:
            break;

        case ActionType::Sleep:
            // TODO
            if (action.RemainingTicks > 0){
                action.RemainingTicks--;
            }

            if (action.RemainingTicks == 0){
                need.Energy += 40;
                needSystem.Clamp(need);
                FinishAction(entity, world);
            }
            break;

        case ActionType::Eat:
        {
            ResourceComponent& resourceComponent = world.GetResourceComponent();

            if (action.TargetEntity == INVALID_ENTITY){
                FinishAction(entity, world);
                break;
            }

            if (!resourceComponent.Has(action.TargetEntity)){
                FinishAction(entity, world);
                break;
            }

            Resource& resource = resourceComponent.Get(action.TargetEntity);

            if (resource.type != ResourceType::Berry){
                FinishAction(entity, world);
                break;
            }

            inventorySystem.AddItem(ItemType::Berry, 1, inventory);

            resourceComponent.Remove(action.TargetEntity);

            need.Hunger -= 10;
            needSystem.Clamp(need);

            FinishAction(entity, world);

            break;
        }

        case ActionType::Move:
            // TODO
            if (action.RemainingTicks > 0){
                action.RemainingTicks--;
            }

            if (action.RemainingTicks == 0){
                FinishAction(entity, world);
            }
            break;

        case ActionType::Drink:
        {
            ResourceComponent& resourceComponent = world.GetResourceComponent();

            if (action.TargetEntity == INVALID_ENTITY){
                FinishAction(entity, world);
                break;
            }

            if (!resourceComponent.Has(action.TargetEntity)){
                FinishAction(entity, world);
                break;
            }

            Resource& resource = resourceComponent.Get(action.TargetEntity);

            if (resource.type != ResourceType::Water){
                FinishAction(entity, world);
                break;
            }

            inventorySystem.AddItem(ItemType::Water, 1, inventory);

            resourceComponent.Remove(action.TargetEntity);

            need.Thirst -= 10;
            needSystem.Clamp(need);

            FinishAction(entity, world);

            break;
        }


    }
}

void ActionSystem::Update(World& world){
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

        ExecuteAction(target, world);
    }

};

void ActionSystem::FinishAction(Entity entity, World& world){
    ActionComponent& actionComponent = world.GetActionComponent();

    Action& action = actionComponent.Get(entity);

    action.type = ActionType::Idle;

    action.RemainingTicks = 0;

    action.TargetEntity = INVALID_ENTITY;

    action.TargetPosition = {INVALID_POS, INVALID_POS};
}