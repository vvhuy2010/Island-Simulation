#pragma once
#include <vector>
#include "Position.h"
#include "Entity.h"
// #include <string.h>

enum class VisibleType{
    Human,
    Tree,
    Berry,
    Stone,
    Water,
    Animal,
    Unknown
};

struct VisibleEntity{
    Position position;
    Entity entity;
    
    float dist;
    VisibleType visibleType;
};