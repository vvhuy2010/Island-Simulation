#pragma once
#include "Entity.h"
#include "Position.h"
#include "ActionType.h"


class Plan{

public:
    ActionType action;
    Entity TargetEntity;
    Position TargetPosition;
    int Priority;
};