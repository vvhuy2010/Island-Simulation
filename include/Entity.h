#pragma once
#include <limits>
#include <cstdint>
#include <cstddef>
using Entity = uint32_t;

constexpr Entity INVALID_ENTITY = 0;
constexpr size_t INVALID_INDEX = std::numeric_limits<size_t>::max();
