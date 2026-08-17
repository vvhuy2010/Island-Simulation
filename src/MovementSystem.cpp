#include "MovementSystem.h"
#include "World.h"
#include "AgentComponent.h"
#include "PositionComponent.h"
#include "ActionComponent.h"

void MovementSystem::Update(World& world){

    AgentComponent& agentComponent = world.GetAgentComponent();
    PositionComponent& positionComponent = world.GetPositionComponent();
    ActionComponent& actionComponent = world.GetActionComponent();

    const auto& agents = agentComponent.GetEntities();

    for (Entity entity : agents){

        Action& action = actionComponent.Get(entity);

        if (action.type != ActionType::Move){
            continue;
        }

        Position& position = positionComponent.Get(entity);

        if (position.x < action.TargetPosition.x){
            position.x++;
        }
        else if (position.x > action.TargetPosition.x){
            position.x--;
        }
        else if (position.y < action.TargetPosition.y){
            position.y++;
        }
        else if (position.y > action.TargetPosition.y){
            position.y--;
        }

        if (position.x == action.TargetPosition.x &&
            position.y == action.TargetPosition.y)
        {
            action.type = ActionType::Eat;
        }
    }
}