#pragma once
#include "Entity.h"

struct Position{
    float x;
    float y;
};

constexpr float INVALID_POS = std::numeric_limits<size_t>::max();
