#include "Camera.h"
#include "Renderer.h"
#include "Cube.h"
namespace core {

class GameEngine {
public:
  GameEngine();

  void Init();
  void Run();
  void Shutdown();

private:
  graphics::Renderer *renderer;
  graphics::Camera camera;
  double deltatime;
  void processInput();

};

}; // namespace core
