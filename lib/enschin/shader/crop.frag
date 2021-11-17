#version 330 core
in vec2 v_TexCoord;
layout(location = 0) out vec4 color;
uniform sampler2D u_Texture;
uniform vec4 u_NewCoords;

void main() {
    if (v_TexCoord.x > u_NewCoords.x &&
    v_TexCoord.x < u_NewCoords.y &&
    v_TexCoord.y < u_NewCoords.z &&
    v_TexCoord.y > u_NewCoords.a) {
        color = texture(u_Texture, v_TexCoord);
    }else{
        color = vec4(0);
    }
}
