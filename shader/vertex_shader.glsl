#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexCoord;
out vec4 vertexColor;
out vec2 TexCoord;
uniform mat4 proj;
uniform mat4 view;
uniform mat4 model;
vec4 pos;
void main() {
    vec4 pos = proj * view * model * vec4(aPos, 1.0);
    gl_Position = pos;
    vertexColor = vec4(sin(pos.x), cos(pos.y), pos.z, 1.0);
    TexCoord = aTexCoord;
}
