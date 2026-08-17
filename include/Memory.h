#pragma once

#include "Entity.h"
#include "Position.h"
#include <vector>

enum class MemoryType{
    SeenResource,
    SeenAgent
};

struct Memory
{
    MemoryType type;
    Entity targetEntity = INVALID_ENTITY;
    Position position = {INVALID_POS, INVALID_POS};

    uint64_t tick = 0;
};
