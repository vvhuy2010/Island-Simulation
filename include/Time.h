#pragma once

#include <cstdint>

struct SimulationTime
{
    uint64_t day;
    uint64_t hour;
    uint64_t minute;
    uint64_t second;
    uint64_t tick;
};

class Time
{
public:
    static constexpr uint64_t TICKS_PER_SECOND = 10;

    static constexpr uint64_t TICKS_PER_MINUTE =
        60 * TICKS_PER_SECOND;

    static constexpr uint64_t TICKS_PER_HOUR =
        60 * TICKS_PER_MINUTE;

    static constexpr uint64_t TICKS_PER_DAY =
        24 * TICKS_PER_HOUR;
};