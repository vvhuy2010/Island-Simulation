#pragma once

#include "Entity.h"
#include "Position.h"
#include "ComponentStorage.h"

class PositionComponent : public ComponentStorage<Position>
{
};