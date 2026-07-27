// #include "ObservationSystem.h"
#include "NeedComponent.h"
#include "NeedSystem.h"

void NeedSystem::UpdateNeed(Entity entity, World& world){
    // World& world;
    NeedComponent& ne = world.GetNeedComponent();
    EntityManager& em = world.GetEntityManager();
    const auto& entities = em.GetAllEntities();
    Need& need = ne.Get(entity);

        // ne.Clear();

        // Position& agentPos = pos.Get(entities[target]);

    need.Energy -= 1;
    need.Thirst += 1;
    need.Hunger += 1;

    Clamp(need);
}

void NeedSystem::Update(World& world){
    EntityManager& em = world.GetEntityManager();
    const auto& entities = em.GetAllEntities();
    AgentComponent& ag = world.GetAgentComponent();
    NeedComponent& ne = world.GetNeedComponent();
    // AgentComponent& ag = world.GetAgentComponent();

    const auto& agents = ag.GetEntities();
    for (Entity target: agents){
        // if (!ag.Has(entities[target])){
        //     continue;
        // }

        UpdateNeed(target, world);
    }

};

float NeedSystem::Limit(float fl){
    if (fl > 100){
        return 100;
    }else if (fl < 0){
        return 0;
    }
    return fl;
}

void NeedSystem::Clamp(Need& need){
    need.Energy = Limit(need.Energy);
    need.Hunger = Limit(need.Hunger);
    need.Thirst = Limit(need.Thirst);
}
