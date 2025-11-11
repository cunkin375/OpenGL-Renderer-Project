#version 460 core

out vec4 fColor;

in vec3 vColor;
in vec2 vTexCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
    fColor = mix(texture(texture1, vTexCoord), texture(texture2, vTexCoord), 0.2);
} // end main
