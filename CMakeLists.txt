cmake_minimum_required(VERSION 3.20)

project(IslandSimulation)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(
    IslandSimulation
    src/main.cpp
    src/EntityManager.cpp
    src/World.cpp
    src/MovementSystem.cpp
    src/HealthSystem.cpp
    src/Simulation.cpp
    src/ObservationSystem.cpp
    src/Observation.cpp
    src/NeedSystem.cpp
    src/ActionSystem.cpp
    src/InventorySystem.cpp
    src/PlannerSystem.cpp
    src/DecisionSystem.cpp
    src/MemorySystem.cpp
)