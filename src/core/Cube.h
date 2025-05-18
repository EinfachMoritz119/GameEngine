#include "Object.h"

namespace core {

class Cube : public Object {

  public:
  Cube(glm::vec3 position);

  void render();
};

};
