#version 330 core
layout(location = 0) in vec3 aPos;

out vec4 vertexColor;
uniform mat4 proj;
uniform mat4 view;
uniform mat4 model;

void main() {
    gl_Position = proj * view * model * vec4(aPos, 1.0);
    vertexColor = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}
