cmake_minimum_required(VERSION 3.28)
project(GameEngine)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Pakete finden
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# GLAD als Bibliothek
add_library(glad src/glad.c)
target_include_directories(glad PUBLIC ${CMAKE_SOURCE_DIR}/dependencies/include)

# Executable erstellen
add_executable(${PROJECT_NAME}
    src/main.cpp
    # weitere cpp-Dateien hier einfügen
    src/core/Object.cpp
    src/core/GameEngine.cpp
    src/core/Cube.cpp
    src/graphics/Shader.cpp
    src/graphics/Camera.cpp
    src/graphics/Renderer.cpp

)

# Projektverzeichnis einbinden (für deine eigenen Header z. B. core/game.h)
target_include_directories(${PROJECT_NAME}
    PRIVATE ${CMAKE_SOURCE_DIR}/src
    PRIVATE ${CMAKE_SOURCE_DIR}/src/core
    PRIVATE ${CMAKE_SOURCE_DIR}/src/graphics
    PRIVATE ${CMAKE_SOURCE_DIR}/dependencies/include
)

# Bibliotheken linken
target_link_libraries(${PROJECT_NAME}
    glad
    glfw
    OpenGL::GL
)

