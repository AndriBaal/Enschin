#version 330 core
precision mediump float;
in vec2 v_TexCoord;
uniform sampler2D u_Texture;

void main()
{
	color = texture2D(u_Texture, v_TexCoord);
}