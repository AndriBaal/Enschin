#version 330 core
in vec2 v_TexCoord;
layout(location = 0) out vec4 color;
uniform sampler2D u_Texture;

uniform float percentLeft, percentRight, percentTop, percentBottom;

void main()
{
    color = texture(u_Texture, v_TexCoord);
}
