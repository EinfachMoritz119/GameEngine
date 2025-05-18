#include "Renderer.h"

#include <filesystem>
#include <iostream>

namespace graphics {

void framebuffer_size_callback(GLFWwindow *window, int width, int height);

Renderer::Renderer() {
  if (!glfwInit()) {
    fprintf(stderr, "Failed to init GLFW\n");
  }
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
  shaderProgram =
      new Shader("shader/vertex_shader.glsl", "shader/fragment_shader.glsl");
  Init();
}

void Renderer::Init() {

  shaderProgram->use();
  glm::mat4 proj = glm::perspective(
      glm::radians(45.0f), ((float)WIDTH / (float)HEIGHT), 0.1f, 100.0f);
  shaderProgram->setMat4("proj", proj);
}

void Renderer::Render(const Camera &cam) {

  glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  if (objects.empty()) {
    std::cout << "Objects are empty" << std::endl;
  }
  shaderProgram->use();

  glm::mat4 view = cam.GetViewMatrix();
  shaderProgram->setMat4("view", view);

  for (core::Object &object : objects) {

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(20.0f) * (float)glfwGetTime(), glm::vec3(0.0f,1.0f,0.0f));
    shaderProgram->setMat4("model", model);
    object.render();
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
