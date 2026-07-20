#include "World.h"
#include "Simulation.h"
#include <iostream>

signed main(){
    World world;

    // world.GenerateWorld();
    Entity alice = world.SpawnHuman("Alice", {10, 10});
    Entity john = world.SpawnHuman("John", {50, 50});

    world.SpawnTree({12, 11});
    world.SpawnBerry({18, 10});
    world.Update();

    Observation& observation = world.GetObservationComponent().Get(alice);

    std::cout << world.GetObservationComponent().Has(alice) << "\n";

    const auto& visible = observation.Get();

    std::cout << visible.size() << "\n";

    // const auto& visible = observation.Get();

for (const auto& v : visible)
{
    std::cout << "Entity: " << v.entity
              << " Type: " << (int)v.visibleType
              << " Dist: " << v.dist
              << " Pos: (" << v.position.x
              << ", " << v.position.y << ")\n";
}

}