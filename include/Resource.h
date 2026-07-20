#pragma once

enum class ResourceType
{
    Tree,
    Berry,
    Stone,
    Water
};

struct Resource
{
    ResourceType type;
};