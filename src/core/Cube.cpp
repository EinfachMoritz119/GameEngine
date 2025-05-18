#include "Cube.h"

namespace core {

std::vector<Vertex> cubeVertices = {
    // Front face (z = 0.5)
    {{-0.5f, -0.5f,  0.5f}},
    {{ 0.5f, -0.5f,  0.5f}},
    {{ 0.5f,  0.5f,  0.5f}},

    {{ 0.5f,  0.5f,  0.5f}},
    {{-0.5f,  0.5f,  0.5f}},
    {{-0.5f, -0.5f,  0.5f}},

    // Back face (z = -0.5)
    {{ 0.5f, -0.5f, -0.5f}},
    {{-0.5f, -0.5f, -0.5f}},
    {{-0.5f,  0.5f, -0.5f}},

    {{-0.5f,  0.5f, -0.5f}},
    {{ 0.5f,  0.5f, -0.5f}},
    {{ 0.5f, -0.5f, -0.5f}},

    // Left face (x = -0.5)
    {{-0.5f, -0.5f, -0.5f}},
    {{-0.5f, -0.5f,  0.5f}},
    {{-0.5f,  0.5f,  0.5f}},

    {{-0.5f,  0.5f,  0.5f}},
    {{-0.5f,  0.5f, -0.5f}},
    {{-0.5f, -0.5f, -0.5f}},

    // Right face (x = 0.5)
    {{ 0.5f, -0.5f,  0.5f}},
    {{ 0.5f, -0.5f, -0.5f}},
    {{ 0.5f,  0.5f, -0.5f}},

    {{ 0.5f,  0.5f, -0.5f}},
    {{ 0.5f,  0.5f,  0.5f}},
    {{ 0.5f, -0.5f,  0.5f}},

    // Top face (y = 0.5)
    {{-0.5f,  0.5f,  0.5f}},
    {{ 0.5f,  0.5f,  0.5f}},
    {{ 0.5f,  0.5f, -0.5f}},

    {{ 0.5f,  0.5f, -0.5f}},
    {{-0.5f,  0.5f, -0.5f}},
    {{-0.5f,  0.5f,  0.5f}},

    // Bottom face (y = -0.5)
    {{-0.5f, -0.5f, -0.5f}},
    {{ 0.5f, -0.5f, -0.5f}},
    {{ 0.5f, -0.5f,  0.5f}},

    {{ 0.5f, -0.5f,  0.5f}},
    {{-0.5f, -0.5f,  0.5f}},
    {{-0.5f, -0.5f, -0.5f}},
};

int CubeIndicies[] = {
  1,2,3,
  2,3,1,
};
Cube::Cube(glm::vec3 position) : Object(position, cubeVertices, CubeIndicies){


  GLuint VAO, VBO; 
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);


  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));

  glBindVertexArray(0);
  vertex_array = VAO;
}

void Cube::Cube::render() {
    glBindVertexArray(vertex_array);
    glDrawArrays(GL_TRIANGLES,0,cubeVertices.size());
}
};
