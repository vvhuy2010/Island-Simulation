#pragma once

#include "Entity.h"
// #include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
#include <stack>
#include <stdexcept>
#include "Resource.h"
#include "ComponentStorage.h"
class ResourceComponent : public ComponentStorage<Resource>
{
};