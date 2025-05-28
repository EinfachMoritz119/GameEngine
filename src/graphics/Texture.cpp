#define STB_IMAGE_IMPLEMENTATION
#include <stb-master/stb_image.h>
#include "Texture.h"
#include <filesystem>
#include <glad/glad.h>
#include <iostream>

namespace graphics{

Texture::Texture(const std::string& path) {
  glGenTextures(1, &textureID);
  glBindTexture(GL_TEXTURE_2D, textureID);
std::cout << "Loading texture from: " << std::filesystem::absolute(path) << std::endl;
  // Texture wrapping/filtering options
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  stbi_set_flip_vertically_on_load(true); // for OpenGL texture coordinates
  unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
  if (data) {
    GLenum format = nrChannels == 4 ? GL_RGBA : GL_RGB;
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  } else {
    std::cerr << "Failed to load texture: " << path << std::endl;
  }
  stbi_image_free(data);
}

Texture::~Texture() {
  glDeleteTextures(1, &textureID);
}

void Texture::Bind(unsigned int unit) const {
  glActiveTexture(GL_TEXTURE0 + unit);
  glBindTexture(GL_TEXTURE_2D, textureID);
}

void Texture::Unbind() const {
  glBindTexture(GL_TEXTURE_2D, 0);
}

GLuint Texture::GetID() const {
  return textureID;
}
};
