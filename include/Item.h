#pragma once

enum class ItemType{
    Berry,
    Wood,
    Stone,
    Water,
};

struct Item
{
    ItemType type;
    int quantity;
};
