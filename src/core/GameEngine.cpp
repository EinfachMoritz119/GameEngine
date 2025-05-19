#include "GameEngine.h"
#include "GLFW/glfw3.h"
#include <vector>

namespace core {

GameEngine::GameEngine() {
  Init();
  camera = graphics::Camera(glm::vec3(0.0f, 0.0f, 3.0f));
}
void GameEngine::Init() {
  renderer = new graphics::Renderer();
  std::vector<Vertex> vertices = {
      {glm::vec3(-0.5f, -0.5f, 0.0f)}, // bottom left
      {glm::vec3(0.5f, -0.5f, 0.0f)},  // bottom right
      {glm::vec3(-0.5f, 0.5f, 0.0f)},  // top left
                                       //
      {glm::vec3(0.5f, -0.5f, 0.0f)},  // bottom right
      {glm::vec3(0.5f, 0.5f, 0.0f)},   // top right
      {glm::vec3(-0.5f, 0.5f, 0.0f)},  // top left
  };
  std::vector<Vertex> cubeVertices = {
    // Front face (z = 0.5)
    {{-0.5f, -0.5f, 0.5f}},
    {{0.5f, -0.5f, 0.5f}},
    {{0.5f, 0.5f, 0.5f}},

    {{0.5f, 0.5f, 0.5f}},
    {{-0.5f, 0.5f, 0.5f}},
    {{-0.5f, -0.5f, 0.5f}},

    // Back face (z = -0.5)
    {{0.5f, -0.5f, -0.5f}},
    {{-0.5f, -0.5f, -0.5f}},
    {{-0.5f, 0.5f, -0.5f}},

    {{-0.5f, 0.5f, -0.5f}},
    {{0.5f, 0.5f, -0.5f}},
    {{0.5f, -0.5f, -0.5f}},

    // Left face (x = -0.5)
    {{-0.5f, -0.5f, -0.5f}},
    {{-0.5f, -0.5f, 0.5f}},
    {{-0.5f, 0.5f, 0.5f}},

    {{-0.5f, 0.5f, 0.5f}},
    {{-0.5f, 0.5f, -0.5f}},
    {{-0.5f, -0.5f, -0.5f}},

    // Right face (x = 0.5)
    {{0.5f, -0.5f, 0.5f}},
    {{0.5f, -0.5f, -0.5f}},
    {{0.5f, 0.5f, -0.5f}},

    {{0.5f, 0.5f, -0.5f}},
    {{0.5f, 0.5f, 0.5f}},
    {{0.5f, -0.5f, 0.5f}},

    // Top face (y = 0.5)
    {{-0.5f, 0.5f, 0.5f}},
    {{0.5f, 0.5f, 0.5f}},
    {{0.5f, 0.5f, -0.5f}},

    {{0.5f, 0.5f, -0.5f}},
    {{-0.5f, 0.5f, -0.5f}},
    {{-0.5f, 0.5f, 0.5f}},

    // Bottom face (y = -0.5)
    {{-0.5f, -0.5f, -0.5f}},
    {{0.5f, -0.5f, -0.5f}},
    {{0.5f, -0.5f, 0.5f}},

    {{0.5f, -0.5f, 0.5f}},
    {{-0.5f, -0.5f, 0.5f}},
    {{-0.5f, -0.5f, -0.5f}},
};
  int indices[] = {
      0, 1, 2, 1, 3, 2,
  };
  Object object = Object(glm::vec3(0.0f, 0.0f, 0.0f), vertices, indices);
  Object cube = Object(glm::vec3(2.0f, 0.0f, 0.0f), cubeVertices, indices);
  renderer->AddObject(object);
  renderer->AddObject(cube);
  deltatime = glfwGetTime();
}

void GameEngine::Run() {
  float currentTime = glfwGetTime();
  float lastTime = currentTime;
  while (glfwGetKey(renderer->GetWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS &&
         glfwWindowShouldClose(renderer->GetWindow()) == 0) {
    currentTime = glfwGetTime();
    deltatime = currentTime - lastTime;
    lastTime = currentTime;
    renderer->Render(camera);
    processInput();
  }
}
void GameEngine::processInput() {
  if (glfwGetKey(renderer->GetWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(renderer->GetWindow(), 1);
  }
  if (glfwGetKey(renderer->GetWindow(), GLFW_KEY_W) == GLFW_PRESS) {
    camera.ProcessKeyboard(FORWARD, deltatime);
  }
  if (glfwGetKey(renderer->GetWindow(), GLFW_KEY_S) == GLFW_PRESS) {

    camera.ProcessKeyboard(BACKWARD, deltatime);
  }
  if (glfwGetKey(renderer->GetWindow(), GLFW_KEY_A) == GLFW_PRESS) {
    camera.ProcessKeyboard(LEFT, deltatime);
  }
  if (glfwGetKey(renderer->GetWindow(), GLFW_KEY_D) == GLFW_PRESS) {
    camera.ProcessKeyboard(RIGHT, deltatime);
  }
}
}; // namespace core
