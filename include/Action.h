#pragma once

#include "Entity.h"
#include "Position.h"
#include "Time.h"
#include "ActionType.h"

struct Action
{
    ActionType type = ActionType::Idle;
    uint64_t RemainingTicks = 0;

    Entity TargetEntity = INVALID_ENTITY;
    Position TargetPosition = {INVALID_POS, INVALID_POS};
};