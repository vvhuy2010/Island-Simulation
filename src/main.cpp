#include "World.h"
#include "Simulation.h"
#include <iostream>

signed main(){
    World world;

    Entity alice = world.SpawnHuman("Alice", {10, 10});
    Entity john = world.SpawnHuman("John", {50, 50});

    MemoryComponent& memoryComponent = world.GetMemoryComponent();

    world.SpawnTree({12, 11});
    world.SpawnBerry({18, 10});

    world.Update();

    Observation& observation =
        world.GetObservationComponent().Get(alice);

    std::cout << "Observation exists: "
              << world.GetObservationComponent().Has(alice)
              << "\n";

    const auto& visible = observation.Get();

    std::cout << "Visible objects: "
              << visible.size()
              << "\n";

    for (const auto& v : visible){
        std::cout << "Entity: " << v.entity
                  << " Type: " << (int)v.visibleType
                  << " Dist: " << v.dist
                  << " Pos: (" << v.position.x
                  << ", " << v.position.y << ")\n";
    }

    std::cout << "\n=== MEMORY ===\n";

    const auto& memories = memoryComponent.Get(alice);

    std::cout << "Alice memories: "
              << memories.size()
              << "\n";

    for (const auto& memory : memories){
        std::cout << "Memory Entity: "
                  << memory.targetEntity
                  << " Pos: ("
                  << memory.position.x
                  << ", "
                  << memory.position.y
                  << ") Tick: "
                  << memory.tick
                  << "\n";
    }

    std::cout << "\n=== SIMULATION ===\n";

    for (int i = 0; i < 20; i++){
        world.Update();

        std::cout << "Tick: "
                  << world.GetCurrentTick()
                  << " | Memories: "
                  << memoryComponent.Get(alice).size()
                  << "\n";
    }
}