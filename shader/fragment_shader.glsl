#version 330 core
out vec4 FragColor;

in vec2 TexCoord;
uniform sampler2D texture1;
in vec4 vertexColor;
void main() {
    FragColor = texture(texture1, TexCoord) * vertexColor;
}
