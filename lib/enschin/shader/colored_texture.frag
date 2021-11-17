#version 330 core

layout(location = 0) out vec4 color;

in vec2 v_TexCoord;

uniform vec4 u_Color;
uniform sampler2D u_Texture;

void main()
{
	vec4 t = texture(u_Texture, v_TexCoord);
	t.rgb *= (1.0-u_Color.a);
	t.rgb += u_Color.rgb * u_Color.a;
	color = t;
}