//
// Created by Dávid Horváth on 2022. 04. 06..
//

#pragma once
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>
#include <iostream>
#include <vector>
#include <optional>

// stores the queue family indexes in members
class QueueFamilyIndices {
public:
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentationFamily;

    bool IsComplete()
    {
        // Only returns true if both members have a value
        return (graphicsFamily.has_value() && presentationFamily.has_value());
    }
};




