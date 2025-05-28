#ifndef OBJECT_H
#define OBJECT_H
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <vector>
namespace core {
struct Vertex {
  glm::vec3 position;
  glm::vec2 texCoords;
};
class Object {

public:
  Object(glm::vec3 position, std::vector<Vertex> vertices, int indices[]);
  void Init();
  void update();
  void render();
  GLuint GetVAO();

  glm::vec3 m_position;
  std::vector<Vertex> m_vertices;
  std::vector<int> m_indices;
  GLuint vertex_array;
  private:
  float acceleration = -9.81f;
  float time;
  float velocity = 0;

  float deltatime;
  float lasttime;
};
}; // namespace core
#endif // !OBJECT_H
