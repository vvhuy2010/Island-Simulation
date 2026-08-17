#pragma once

#include "ComponentStorage.h"
#include "Memory.h"

class MemoryComponent : public ComponentStorage<std::vector<Memory>>
{
};