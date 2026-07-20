#pragma once
#include "Position.h"
#include "Entity.h"
#include "VisibleEntity.h"

class Observation{

public:
    void Observe(const VisibleEntity& visible);
    bool Empty();
    const std::vector<VisibleEntity>& Get();
    // void Remove();
    void Clear();
    size_t Size() const;

private:
    std::vector<VisibleEntity> observed;
};