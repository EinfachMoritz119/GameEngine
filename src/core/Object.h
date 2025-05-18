
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <vector>
namespace core {
struct Vertex {
  glm::vec3 position;
};
class Object {

public:
  Object(glm::vec3 position, std::vector<Vertex> vertices, int indices[]);
  void render();
  GLuint GetVAO();

  glm::vec3 position;
  std::vector<Vertex> vertices;
  std::vector<int> indices;
  GLuint vertex_array;
};
}; // namespace core
