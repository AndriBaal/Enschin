#version 330 core

layout(location = 0) out vec4 color;
in vec2 v_TexCoord;
uniform float u_TotalTime;

void main() {
    vec3 col = 0.5 + 0.5*cos(u_TotalTime+v_TexCoord.xyx+vec3(0,2,4));
    color = vec4(col,1.0);

}
