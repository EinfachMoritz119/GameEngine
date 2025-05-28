#ifndef TEXTURE_H
#define TEXTURE_H
#include <string>
#include <glad/glad.h>

namespace graphics {

class Texture {
public:
  Texture(const std::string& path);
  ~Texture();

  void Bind(unsigned int unit = 0) const;
  void Unbind() const;
  GLuint GetID() const;

private:
  GLuint textureID;
  int width, height, nrChannels;
};
};
#endif
