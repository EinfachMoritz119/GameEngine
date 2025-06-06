#include "Camera.h"
#include "glm/gtx/dual_quaternion.hpp"
#include <iostream>
#include <glm/gtx/string_cast.hpp>
namespace graphics {

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
    : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED),
      MouseSensitivity(SENSITIVITY), Zoom(ZOOM) {
  Position = position;
  WorldUp = up;
  Yaw = yaw;
  Pitch = pitch;
  updateCameraVectors();
}

Camera::Camera(float posX, float posY, float posZ, float upX, float upY,
               float upZ, float yaw, float pitch)
    : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED),
      MouseSensitivity(SENSITIVITY), Zoom(ZOOM) {
  Position = glm::vec3(posX, posY, posZ);
  WorldUp = glm::vec3(upX, upY, upZ);

  Yaw = yaw;
  Pitch = pitch;
  updateCameraVectors();
}

glm::mat4 Camera::GetViewMatrix() const {
  glm::mat4 view = glm::lookAt(Position, Position + Front, Up);
  return view;
}

void Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime)
{
	float velocity = MovementSpeed * deltaTime;
	if (direction == FORWARD)
	{
		float y = Position.y;
		Position += Front * velocity;
		Position.y = y;
	}
	if (direction == BACKWARD)
	{
		float y = Position.y;
		Position -= Front * velocity;
		Position.y = y;
	}
	if (direction == LEFT)
	{
		Position -= Right * velocity;
	}
	if (direction == RIGHT)
	{
		Position += Right * velocity;
	}
	if (direction == UP)
	{
		Position += WorldUp * velocity;
	}
	if (direction == DOWN)
	{
		Position -= WorldUp * velocity;
	}
	updateCameraVectors();
}

void Camera::ProcessMouseMovement(float xoffset, float yoffset)
{
	xoffset *= MouseSensitivity;
	yoffset *= MouseSensitivity;
	Yaw += xoffset;
	Pitch += yoffset;
	if (Pitch > 89.0f)
		Pitch = 89.0f;
	if (Pitch < -89.0f)
		Pitch = -89.0f;
	updateCameraVectors();
}
void Camera::updateCameraVectors()
{
	glm::vec3 front;
	front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	front.y = sin(glm::radians(Pitch));
	front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	Front = glm::normalize(front);
	Right = glm::normalize(glm::cross(Front, WorldUp));
	Up = glm::normalize(glm::cross(Right, Front));

}
}; // namespace graphics
