//
// Created by Dávid Horváth on 2022. 04. 06..
//

#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <fstream>

#include "QueueFamilyIndices.h"
#include "SwapchainSupportDetails.h"

class Engine {
public:
    void Run();

private:
    /// Variables
    GLFWwindow* window;
    VkInstance instance;
    VkSurfaceKHR surface;

    // Swapchain
    VkSwapchainKHR swapchain;
    std::vector<VkImage> swapchainImages;
    VkFormat swapchainImageFormat;
    VkExtent2D swapchainExtent;
    std::vector<VkImageView> swapchainImageViews;

    // Pipeline
    VkRenderPass renderPass;
    VkPipelineLayout pipelineLayout;
    VkPipeline graphicsPipeline;

    // Frame buffers
    std::vector<VkFramebuffer> swapchainFrameBuffers;

    // Physical device
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    // All required extensions should be here
    const std::vector<const char*> deviceExtensions = {VK_KHR_SWAPCHAIN_EXTENSION_NAME};
    VkQueue graphicsQueue;
    VkQueue presentQueue;

    // Logical device
    VkDevice device;

    // Commands
    VkCommandPool commandPool;
    VkCommandBuffer commandBuffer;

    // Synchronization
    VkSemaphore imageAvailableSemaphore;
    VkSemaphore renderFinishedSemaphore;
    VkFence inFlightFence;


    /// Validation layers
    const std::vector<const char*> validationLayers = {"VK_LAYER_KHRONOS_validation"};

    #ifdef NDEBUG
        const bool enableValidationLayers = false;
    #else
        const bool enableValidationLayers = false;
    #endif


    /// Methods
    // Regular
    void InitWindow();
    void InitVulkan();
    void MainLoop();
    void CleanUp();

    // Vulkan
    void CreateInstance();
    void CreateSurface();
    void PickPhysicalCard();
    void CreateLogicalDevice();

    // region Checking and getting physical device properties
    bool IsDeviceSuitable(VkPhysicalDevice device);
    bool CheckDeviceExtensionSupport(VkPhysicalDevice device);
    SwapchainSupportDetails QuerySwapChainSupport(VkPhysicalDevice device);
    QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);

    // Surface settings
    VkSurfaceFormatKHR ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
    VkPresentModeKHR ChooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
    VkExtent2D ChooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
    void CreateSwapchain();
    void CreateImageViews();
    //endregion

    // Graphics pipelines
    void CreateGraphicsPipeline();
    VkShaderModule CreateShaderModule(const std::vector<char>& code);
    void CreateRenderPass();
    void CreateFrameBuffers();
    static std::vector<char> ReadFile(const std::string filePath);

    // Commands
    void CreateCommandPool();
    void CreateCommandBuffer();
    void RecordCommandBuffer(VkCommandBuffer cBuffer, uint32_t imageIndex);

    // Drawing
    void DrawFrame();

    // Synchronization
    void CreateSyncObjects();

    bool CheckValidationLayers();
};
