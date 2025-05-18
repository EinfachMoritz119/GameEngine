#include "Shader.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <filesystem>
graphics::Shader::Shader(const char *vertex_source,
                         const char *fragment_source) {

  // 1. retrieve the vertex/fragment source code from filePath
  std::string vertexCode;
  std::string fragmentCode;
  std::ifstream vShaderFile;
  std::ifstream fShaderFile;
  // ensure ifstream objects can throw exceptions:
  vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

  try {
    // open files
    vShaderFile.open(vertex_source);
    fShaderFile.open(fragment_source);
    std::stringstream vShaderStream, fShaderStream;
    // read file's buffer contents into streams
    vShaderStream << vShaderFile.rdbuf();
    fShaderStream << fShaderFile.rdbuf();
    // close file handlers
    vShaderFile.close();
    fShaderFile.close();
    // convert stream into string
    vertexCode = vShaderStream.str();
    fragmentCode = fShaderStream.str();
  } catch (std::ifstream::failure e) {
    std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
  }
  const char *vShaderCode = vertexCode.c_str();
  const char *fShaderCode = fragmentCode.c_str();

  GLuint vertexshader = glad_glCreateShader(GL_VERTEX_SHADER);
  GLuint fragmentshader = glad_glCreateShader(GL_FRAGMENT_SHADER);

  glShaderSource(vertexshader, 1, &vShaderCode, NULL);

  int success;
  char infoLog[512];

  glCompileShader(vertexshader);
  glGetShaderiv(vertexshader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertexshader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
              << infoLog << std::endl;
  }

  glShaderSource(fragmentshader, 1, &fShaderCode, NULL);

  glCompileShader(fragmentshader);
  glGetShaderiv(fragmentshader, GL_COMPILE_STATUS, &success);
  if (!success) {

    glGetShaderInfoLog(fragmentshader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
              << infoLog << std::endl;
  }
  ID = glCreateProgram();
  glAttachShader(ID, vertexshader);
  glAttachShader(ID, fragmentshader);
  glLinkProgram(ID);

  glGetProgramiv(ID, GL_LINK_STATUS, &success);
  if (!success) {

    glGetShaderInfoLog(ID, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
              << infoLog << std::endl;
  }

  glDeleteShader(vertexshader);
  glDeleteShader(fragmentshader);
}

void graphics::Shader::use() { glUseProgram(ID); }

void graphics::Shader::setBool(const std::string &name,
                               const bool value) const {
  glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void graphics::Shader::setInt(const std::string &name, const int value) const {
  glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}
void graphics::Shader::setFloat(const std::string &name,
                                const float value) const {
  glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void graphics::Shader::setVec3(const std::string &name, const glm::vec3 &value) const {
  glUniform1fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}
void graphics::Shader::setMat4(const std::string &name, const glm::mat4 &value) const {
  glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &value[0][0]);
}

