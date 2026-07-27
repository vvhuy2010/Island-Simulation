#pragma once

#include "Entity.h"
#include "Position.h"
#include "Time.h"

enum class ActionType{
    Idle,
    Move,
    Sleep,
    Eat,
    Drink
};

struct Action{
    ActionType type;
    Entity TargetEntity;
    Position TargetPosition;
    uint64_t RemainingTicks;
};