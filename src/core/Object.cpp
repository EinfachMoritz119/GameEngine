#include "Object.h"

#include "GLFW/glfw3.h"
#include "Renderer.h"
#include "glm/gtx/string_cast.hpp"
#include <cstddef>
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

  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                        (void *)offsetof(Vertex, texCoords));

  glBindVertexArray(0);
  vertex_array = VAO;
  lasttime = glfwGetTime();
  time = 0;
  velocity = 0;
}

void Object::update() {
  float currenttime = glfwGetTime();
  deltatime = currenttime - lasttime;
  // if (m_position.y <= 0) {
  //   time = 0;
  //   velocity = 0;
  //
  // } else {
  //
  //   time += deltatime / 16;
  //   std::cout << time << std::endl;
  //   m_position =
  //       glm::vec3(m_position.x, time * (velocity + time * acceleration / 2),
  //                 m_position.z);
  //   velocity += time * acceleration;
  // }
    lasttime = currenttime;
}
void Object::render() {
  glBindVertexArray(vertex_array);
  glDrawArrays(GL_TRIANGLES, 0, m_vertices.size());
}
GLuint Object::GetVAO() { return vertex_array; }
}; // namespace core
