#include "ObservationSystem.h"
#include "HealthComponent.h"
#include "HealthSystem.h"

void ObservationSystem::Update(World& world){
    EntityManager& em = world.GetEntityManager();
    const auto& entities = em.GetAllEntities();
    AgentComponent& ag = world.GetAgentComponent();
    PositionComponent& pos = world.GetPositionComponent();
    ObservationComponent& observationComponent = world.GetObservationComponent();
    ResourceComponent& re = world.GetResourceComponent();
    // AgentComponent& ag = world.GetAgentComponent();

    const auto& agents = ag.GetEntities();
    for (Entity target: agents){
        // if (!ag.Has(entities[target])){
        //     continue;
        // }

        Observation& observation = observationComponent.Get(entities[target]);

        observation.Clear();

        Position& agentPos = pos.Get(entities[target]);

        for (int agentobserve = 0; agentobserve < entities.size(); ++agentobserve){
            if (agentobserve == target){
                continue;
            }

            if (!pos.Has(entities[agentobserve]))
            {
                continue;
            }

            Position& entitypos = pos.Get(entities[agentobserve]);

            float dist = (abs(entitypos.x - agentPos.x) + abs(entitypos.y - agentPos.y));
            constexpr float visionRange = 10.0f;

            if (dist > visionRange){
                // xa naht la 10(chua doi)
                continue;
            }

            VisibleEntity visible;

            visible.entity = entities[agentobserve];
            visible.position = entitypos;
            visible.dist = dist;

            if (ag.Has(entities[agentobserve])){
                visible.visibleType = VisibleType::Human;
            }else if (re.Has(entities[agentobserve])){
                Resource& resource = re.Get(entities[agentobserve]);

                switch(resource.type)   
                {
                    case ResourceType::Tree:
                    visible.visibleType = VisibleType::Tree;
                    break;

                    case ResourceType::Berry:
                    visible.visibleType = VisibleType::Berry;
                    break;

                    case ResourceType::Stone:
                    visible.visibleType = VisibleType::Stone;
                    break;

                    case ResourceType::Water:
                    visible.visibleType = VisibleType::Water;
                    break;
                }
            }else{
                visible.visibleType = VisibleType::Unknown;
            }

            observation.Observe(visible);
        }
    }

};
