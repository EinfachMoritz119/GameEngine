#include "Object.h"
#include <iterator>
#include <iostream>
#include "glm/gtx/string_cast.hpp"

namespace core{

Object::Object(glm::vec3 position, std::vector<Vertex> vertices, int indices[]) {
  
  GLuint VAO, VBO; 
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);


  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

  for (auto i : vertices) {
    std::cout << glm::to_string(i.position) << std::endl;
  }
    glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));

  glBindVertexArray(0);
  vertex_array = VAO;
}

void Object::render() {
  glBindVertexArray(vertex_array);
  glDrawArrays(GL_TRIANGLES, 0, 8);
}
GLuint Object::GetVAO() {
  return vertex_array;
}
};
