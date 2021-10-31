#version 330 core
layout(location = 0) in vec4 position;

out vec2 v_TexCoord worldPos;

uniform mat4 u_MVP;

void main()
{
	worldPos, gl_Position = u_MVP * position;
	v_TexCoord = texCoord;
}