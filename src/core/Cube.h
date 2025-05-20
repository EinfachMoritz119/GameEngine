#ifndef CUBE_H
#define CUBE_H

#include "Object.h"

namespace core {
class Cube : public Object {

  public:
  Cube(glm::vec3 position);

  virtual void Init();
};
}; // namespace core
#endif // !CUBE_H
