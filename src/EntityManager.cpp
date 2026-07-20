#include "EntityManager.h"
#include "Entity.h"
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// using em EntityManager;
Entity EntityManager::Create(){
    Entity entity;
    if (!EntityManager::freeEntities.empty()){
        Entity id = EntityManager::freeEntities.top();
        EntityManager::freeEntities.pop();
        entity = id;
        // return id;
    }else{
        Entity ans = EntityManager::nextEntity;
        EntityManager::nextEntity++;
        entity = ans;
        // return ans;
    }
    if (aliveIndex.size() <= entity){
        aliveIndex.resize(entity + 1, INVALID_INDEX);
    }

    size_t index = aliveEntities.size();

    // aliveEntities.push_back({entity});
    
    aliveEntities.push_back(entity);

    aliveIndex[entity] = index; // 0 

    return entity;
}

bool EntityManager::Has(Entity entity){
    if (entity >= aliveIndex.size()){
        return false;
    }
    else if (aliveIndex[entity] == INVALID_INDEX){
        return false;
    }
    else{
        return true;
    }
}


void EntityManager::Destroy(Entity entity){
    if (!Has(entity)){
        return;
    }
    EntityManager::freeEntities.push(entity);

    size_t index = aliveIndex[entity];

    size_t last_index = aliveEntities.size() - 1;

    aliveEntities[index] = aliveEntities[last_index];

    aliveIndex[aliveEntities[index]] = index;

    aliveEntities.pop_back();

    aliveIndex[entity] = INVALID_INDEX;
}

const std::vector<Entity>& EntityManager::GetAllEntities(){
    return aliveEntities;
};