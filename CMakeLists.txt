cmake_minimum_required(VERSION 3.20)

project(IslandSimulation)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(
    IslandSimulation
    src/main.cpp
    src/EntityManager.cpp
    src/PositionComponent.cpp
    src/HealthComponent.cpp
    src/World.cpp
    src/MovementSystem.cpp
    src/HealthSystem.cpp
    src/Simulation.cpp
    src/VelocityComponent.cpp
    src/AgentComponent.cpp
    src/ResourceComponent.cpp
    src/ObservationSystem.cpp
    src/ObservationComponent.cpp
    src/Observation.cpp
)