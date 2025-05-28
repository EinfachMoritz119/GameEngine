#include "Cube.h"

namespace core {

glm::vec2 uv[] = {
    {0.0f, 0.0f},
    {1.0f, 0.0f},
    {0.0f, 1.0f},
    {1.0f, 1.0f},
};

std::vector<Vertex> cubeVertices = {
    // Front face (z = 0.5)
    {{-0.5f, -0.5f, 0.5f}, uv[0]}, // bottem left
    {{0.5f, -0.5f, 0.5f}, uv[1]}, // bottom right
    {{0.5f, 0.5f, 0.5f}, uv[3]}, // top right

    {{0.5f, 0.5f, 0.5f}, uv[3]},
    {{-0.5f, 0.5f, 0.5f}, uv[2]},
    {{-0.5f, -0.5f, 0.5f}, uv[0]},

    // Back face (z = -0.5)
    {{0.5f, -0.5f, -0.5f}, uv[0]},
    {{-0.5f, -0.5f, -0.5f}, uv[1]},
    {{-0.5f, 0.5f, -0.5f}, uv[3]},

    {{-0.5f, 0.5f, -0.5f}, uv[3]},
    {{0.5f, 0.5f, -0.5f}, uv[2]},
    {{0.5f, -0.5f, -0.5f}, uv[0]},

    // Left face (x = -0.5)
    {{-0.5f, -0.5f, -0.5f}, uv[0]},
    {{-0.5f, -0.5f, 0.5f}, uv[1]},
    {{-0.5f, 0.5f, 0.5f}, uv[3]},

    {{-0.5f, 0.5f, 0.5f}, uv[3]},
    {{-0.5f, 0.5f, -0.5f}, uv[2]},
    {{-0.5f, -0.5f, -0.5f}, uv[0]},

    // Right face (x = 0.5)
    {{0.5f, -0.5f, 0.5f}, uv[0]},
    {{0.5f, -0.5f, -0.5f}, uv[1]},
    {{0.5f, 0.5f, -0.5f}, uv[3]},

    {{0.5f, 0.5f, -0.5f}, uv[3]},
    {{0.5f, 0.5f, 0.5f}, uv[2]},
    {{0.5f, -0.5f, 0.5f}, uv[0]},

    // Top face (y = 0.5)
    {{-0.5f, 0.5f, 0.5f}, uv[0]},
    {{0.5f, 0.5f, 0.5f}, uv[1]},
    {{0.5f, 0.5f, -0.5f}, uv[3]},

    {{0.5f, 0.5f, -0.5f}, uv[3]},
    {{-0.5f, 0.5f, -0.5f}, uv[2]},
    {{-0.5f, 0.5f, 0.5f}, uv[0]},

    // Bottom face (y = -0.5)
    {{-0.5f, -0.5f, -0.5f}, uv[0]},
    {{0.5f, -0.5f, -0.5f}, uv[1]},
    {{0.5f, -0.5f, 0.5f}, uv[3]},

    {{0.5f, -0.5f, 0.5f}, uv[3]},
    {{-0.5f, -0.5f, 0.5f}, uv[2]},
    {{-0.5f, -0.5f, -0.5f}, uv[0]},
};
int indices[] = {0, 1, 2};
Cube::Cube(glm::vec3 position) : Object(position, cubeVertices, indices) {}

void Cube::Init() {}
}; // namespace core
