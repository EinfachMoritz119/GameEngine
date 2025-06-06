#include "GameEngine.h"
#include "Cube.h"
#include "GLFW/glfw3.h"
#include <vector>

namespace core {
float lastX = 800;
float lastY = 450;
float xoffset = 0;
float yoffset = 0;

void mouse_callback(GLFWwindow* window, double xoffset, double yoffset);
GameEngine::GameEngine() {
  Init();
  camera = graphics::Camera(glm::vec3(0.0f, 0.0f, 5.0f));
}
void GameEngine::Init() {
  renderer = new graphics::Renderer();
  glfwSetCursorPosCallback(renderer->GetWindow(), mouse_callback);
  std::vector<Vertex> vertices = {
      {glm::vec3(-0.5f, -0.5f, 0.0f)}, // bottom left
      {glm::vec3(0.5f, -0.5f, 0.0f)},  // bottom right
      {glm::vec3(-0.5f, 0.5f, 0.0f)},  // top left
                                       //
      {glm::vec3(0.5f, -0.5f, 0.0f)},  // bottom right
      {glm::vec3(0.5f, 0.5f, 0.0f)},   // top right
      {glm::vec3(-0.5f, 0.5f, 0.0f)},  // top left
  };
  int indices[] = {
      0, 1, 2, 1, 3, 2,
  };
  Object object = Object(glm::vec3(0.0f, 1.0f, 0.0f), vertices, indices);
  auto cube = Cube(glm::vec3(2.0f, 5.0f, 0.0f));
  auto cub1 = Cube(glm::vec3(-2.0f, 0.0f, 0.0f));
  auto cub2 = Cube(glm::vec3(-4.0f, 0.0f, 0.0f));
  renderer->AddObject(object);
  renderer->AddObject(cube);
  // renderer->AddObject(cub1);
  // renderer->AddObject(cub2);
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
    camera.ProcessMouseMovement(xoffset, yoffset);
    xoffset = 0;
    yoffset = 0;
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
  if (glfwGetKey(renderer->GetWindow(), GLFW_KEY_SPACE) == GLFW_PRESS) {
    camera.ProcessKeyboard(UP, deltatime);
  }
  if (glfwGetKey(renderer->GetWindow(), GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
    camera.ProcessKeyboard(DOWN, deltatime);
  }
  if (glfwGetKey(renderer->GetWindow(), GLFW_KEY_LEFT) == GLFW_PRESS) {
    camera.ProcessMouseMovement(-1,0);
  }
  if (glfwGetKey(renderer->GetWindow(), GLFW_KEY_RIGHT) == GLFW_PRESS) {
    camera.ProcessMouseMovement(1,0);
  }
  if (glfwGetKey(renderer->GetWindow(), GLFW_KEY_UP) == GLFW_PRESS) {
    camera.ProcessMouseMovement(0,1);
  }
  if (glfwGetKey(renderer->GetWindow(), GLFW_KEY_DOWN) == GLFW_PRESS) {
    camera.ProcessMouseMovement(0,-1);
  }
}
void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
// xoffset = xpos - lastx;
// yoffset = lasty - ypos; // reversed since y-coordinates range from bottom to top
// lastx = xpos;
// lasty = ypos;

}
}; // namespace core
