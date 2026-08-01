#include "InventorySystem.h"

bool InventorySystem::HasItem(ItemType itemType, const Inventory& inventory){
    // Inventory inventory;

    for (const auto& i : inventory.items){
        if (i.type == itemType){
            return true;
        }
    }
    // return true;
    return false;
}

uint64_t InventorySystem::GetQuantity(ItemType itemType, const Inventory& inventory){
    if (!HasItem(itemType, inventory)){
        return 0;
    }

    for (const auto& i : inventory.items){
        if (i.type == itemType){
            return i.quantity;
        }
    }
    return 0;
}

void InventorySystem::AddItem(ItemType itemType, uint64_t itemQuantity, Inventory& inventory){
    Item item;
    item.quantity = itemQuantity;
    item.type = itemType;
    // item.quantity += itemQuantity;
    if (!HasItem(itemType, inventory)){
        inventory.items.push_back(item);
        return;
    }
    
    for (auto& i : inventory.items){
        if (i.type == itemType){
            i.quantity += itemQuantity;
            return;
        }
    }
}

void InventorySystem::RemoveItem(ItemType itemType, uint64_t itemQuantity, Inventory& inventory){
    if (!HasItem(itemType, inventory)){
        return;
    }

    for (auto it = inventory.items.begin(); it != inventory.items.end(); ++it){
        if (it->type == itemType){
            if (it->quantity <= itemQuantity){
                inventory.items.erase(it);
            }else{
                it->quantity -= itemQuantity;
            }
            return;
        }
    }
}

