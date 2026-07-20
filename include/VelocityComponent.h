#include "Velocity.h"
#include <vector>

class VelocityComponent{

public:
    void Add(Entity entity, Velocity velocity);

    void Remove(Entity entity);

    Velocity& Get(Entity entity);

    bool Has(Entity entity);

private:
    std::vector<Velocity> denseVelocities;
    std::vector<Entity> denseEntities;
    std::vector<size_t> sparse;
};