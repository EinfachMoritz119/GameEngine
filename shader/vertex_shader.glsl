#version 330 core
layout(location = 0) in vec3 aPos;

out vec4 vertexColor;
uniform mat4 proj;
uniform mat4 view;
uniform mat4 model;
vec4 pos;
void main() {
    vec4 pos = proj * view * model * vec4(aPos, 1.0);
    gl_Position = pos;
    vertexColor = vec4(sin(pos.x), cos(pos.y), pos.z, 1.0);
}
