#pragma once
#include "InventoryComponent.h"

class InventorySystem{

public:
    void AddItem(ItemType type, uint64_t itemQuantity, Inventory& inventory);
    void RemoveItem(ItemType type, uint64_t itemQuantity, Inventory& inventory);
    bool HasItem(ItemType type, const Inventory& inventory);
    uint64_t GetQuantity(ItemType itemType, const Inventory& inventory);
};