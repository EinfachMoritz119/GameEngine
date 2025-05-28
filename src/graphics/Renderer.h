#pragma once
#include "Camera.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Object.h"
#include "Shader.h"
#include "glm/glm.hpp"
#include "Texture.h"
#include "glm/gtc/matrix_transform.hpp"
#include <vector>
const int WIDTH = 1600;
const int HEIGHT = 900;

namespace graphics {

class Renderer {
public:
  Renderer( Camera &cam);
  void Init();
  void AddObject(const core::Object &object);
  void Render();
  void Shutdown();

  GLFWwindow *GetWindow();

private:
  GLFWwindow *window;
  Shader *shaderProgram;
  std::vector<core::Object> objects;
  Camera *camera;
  Texture *texture;
};
}; // namespace graphics
