#include "Observation.h"

const std::vector<VisibleEntity>& Observation::Get()
{
    return observed;
}

bool Observation::Empty(){
    if (!observed.empty()) return false;
    return true;
}

void Observation::Observe(const VisibleEntity& visibleEntity){
    observed.push_back(visibleEntity);
}

void Observation::Clear(){
    observed.clear();
}

size_t Observation::Size() const{
    return observed.size();
}
