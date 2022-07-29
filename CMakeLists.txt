cmake_minimum_required(VERSION 3.21)
project(Learning1)

set(CMAKE_CXX_STANDARD 20)
find_package(glfw3 REQUIRED)
find_package(Vulkan REQUIRED)

add_executable(Learning1 main.cpp Engine.cpp Engine.h QueueFamilyIndices.cpp QueueFamilyIndices.h SwapchainSupportDetails.cpp SwapchainSupportDetails.h)
target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan)