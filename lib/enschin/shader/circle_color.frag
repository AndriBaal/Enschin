#version 330 core

layout(location = 0) out vec4 color;
in vec2 v_TexCoord;
uniform vec4 u_Color;

void main() {
    float d = ceil(-length(v_TexCoord-vec2(0.5, 0.5)) + 0.5);
    color = vec4(u_Color) * d;
}

