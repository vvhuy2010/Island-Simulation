# v0.0.4 - Core Simulation Foundation

Release Date: 2026-07-27

## Added

### Core ECS
- EntityManager
- Sparse ComponentStorage
- World architecture
- Component registration

### Components
- Position
- Health
- Need
- Action
- Resource
- Agent
- Observation

### Systems
- TimeSystem
- NeedSystem
- ActionSystem
- MovementSystem
- HealthSystem

### Features
- Tick-based simulation
- Action execution
- Need decay
- Action completion
- World update pipeline

## Architecture

Implemented the first playable ECS simulation loop.

Entity
↓
Components
↓
Systems
↓
World::Update()

## Next

- Inventory
- Planner
- Visualizer