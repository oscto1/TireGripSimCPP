cmake_minimum_required(VERSION 3.16)
project(GripSim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ------------------------------------------------------------
# Use SFML static libraries
set(SFML_STATIC_LIBRARIES TRUE)

# Tell CMake where SFML is installed (optional if in PATH)

find_package(SFML 3.0 COMPONENTS Graphics Window System REQUIRED)

# ------------------------------------------------------------
# ImGui
add_library(imgui
    external/imgui/imgui.cpp
    external/imgui/imgui_draw.cpp
    external/imgui/imgui_widgets.cpp
    external/imgui/imgui_tables.cpp
)

target_include_directories(imgui PUBLIC
    external/imgui
)

# ------------------------------------------------------------
# ImGui-SFML
add_library(imgui-sfml
    external/imgui-sfml/imgui-SFML.cpp
)

target_include_directories(imgui-sfml PUBLIC
    external/imgui-sfml
    external/imgui
)

target_link_libraries(imgui-sfml
    PUBLIC
        imgui
        SFML::Graphics
        SFML::Window
        SFML::System
)

# ------------------------------------------------------------
# Project sources
file(GLOB SRC_FILES "GripSim/*.cpp")
file(GLOB_RECURSE HEADER_FILES "GripSim/*.h")

# ------------------------------------------------------------
# Executable
add_executable(GripSim
    ${SRC_FILES}
    ${HEADER_FILES}
)

target_compile_definitions(GripSim PRIVATE SFML_STATIC)

target_link_libraries(GripSim
    PRIVATE
        imgui-sfml
        SFML::Graphics
        SFML::Window
        SFML::System
)