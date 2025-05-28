#include "Renderer.h"
#include "GLFW/glfw3.h"
// #include "Texture.h"
#include "Texture.h"
#include "glm/gtx/string_cast.hpp"
#include <filesystem>
#include <iostream>
#include <string>

namespace graphics {

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);

float lastX = WIDTH /2;
float lastY = HEIGHT/2;
Renderer::Renderer() {
  if (!glfwInit()) {
    fprintf(stderr, "Failed to init GLFW\n");
  }
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

// Für macOS zusätzlich nötig:
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  window = glfwCreateWindow(WIDTH, HEIGHT, "Hello OpenGL", NULL, NULL);
  if (window == NULL) {
    fprintf(stderr, "Failed to open GLFW window");
    glfwTerminate();
  }
  glfwMakeContextCurrent(window);

  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cerr << "Failed to init GLAD" << std::endl;
  }
  glEnable(GL_DEPTH_TEST);
  texture = new Texture("assets/textures/container2.png");
  shaderProgram =
      new Shader("shader/vertex_shader.glsl", "shader/fragment_shader.glsl");
 
  Init();
}

void Renderer::Init() {
  shaderProgram->use();
  shaderProgram->setInt("texture1", 0);
  glm::mat4 proj = glm::perspective(
      glm::radians(45.0f), ((float)WIDTH / (float)HEIGHT), 0.1f, 100.0f);
  shaderProgram->setMat4("proj", proj);
}

void Renderer::Render(Camera &cam) {

  glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  if (objects.empty()) {
    std::cout << "Objects are empty" << std::endl;
  }
  shaderProgram->use();
  texture->Bind(0);
  glm::mat4 view = cam.GetViewMatrix();
  shaderProgram->setMat4("view", view);
  int i = 1;
  for (core::Object &object : objects) {

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, object.m_position);
    model = glm::rotate(model, glm::radians(20.0f * i) * (float)glfwGetTime(),
                        glm::vec3(1.0f, 1.0f, 0.0f));
    shaderProgram->setMat4("model", model);
    object.render();
object.update();
    i *= -1;
  }
  glfwSwapBuffers(window);
  glfwPollEvents();
}
void Renderer::AddObject(const core::Object &object) {
  objects.push_back(object);
}
GLFWwindow *Renderer::GetWindow() { return window; }

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

}; // namespace graphics
