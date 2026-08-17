#include "MemorySystem.h"
#include "World.h"

void MemorySystem::Update(World& world){
    AgentComponent& agentComponent = world.GetAgentComponent();

    const auto& agents = agentComponent.GetEntities();

    for (Entity target : agents){
        RememberObservation(target, world);
    }
}

void MemorySystem::RememberObservation(Entity entity, World& world){
    ObservationComponent& observationComponent =
        world.GetObservationComponent();

    MemoryComponent& memoryComponent =
        world.GetMemoryComponent();

    Observation& observation =
        observationComponent.Get(entity);

    std::vector<Memory>& memories =
        memoryComponent.Get(entity);

    std::cout << "MemorySystem: Agent "
              << entity
              << " sees "
              << observation.Get().size()
              << " objects\n";

    for (const auto& visible : observation.Get()){

        std::cout << "Visible type = "
                  << (int)visible.visibleType
                  << '\n';

        Memory memory;

        memory.type = MemoryType::SeenResource;
        memory.targetEntity = visible.entity;
        memory.position = visible.position;
        memory.tick = world.GetCurrentTick();

        memories.push_back(memory);

        std::cout << "Pushed! Memory size = "
                  << memories.size()
                  << '\n';
    }
}