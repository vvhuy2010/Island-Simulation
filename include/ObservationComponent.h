#pragma once

#include "VisibleEntity.h"
#include <vector>
#include "Observation.h"
#include "ComponentStorage.h"
// #include "Observation.h"

class ObservationComponent : public ComponentStorage<Observation>
{
};