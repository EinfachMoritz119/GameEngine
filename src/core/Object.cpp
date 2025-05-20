#include "Object.h"

#include "GLFW/glfw3.h"
#include "glm/gtx/string_cast.hpp"
#include <iostream>

namespace core {

Object::Object(glm::vec3 position, std::vector<Vertex> vertices,
               int indices[]) {

  m_position = position;
  m_vertices = vertices;
  Init();
};
void Object::Init() {
  GLuint VAO, VBO;
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(Vertex),
               m_vertices.data(), GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                        (void *)offsetof(Vertex, position));

  glBindVertexArray(0);
  vertex_array = VAO;
}

void Object::update() {
  m_position = glm::vec3(sin(glfwGetTime()), sin(glfwGetTime()), m_position.z);
}
void Object::render() {
  glBindVertexArray(vertex_array);
  glDrawArrays(GL_TRIANGLES, 0, m_vertices.size());
}
GLuint Object::GetVAO() { return vertex_array; }
}; // namespace core
