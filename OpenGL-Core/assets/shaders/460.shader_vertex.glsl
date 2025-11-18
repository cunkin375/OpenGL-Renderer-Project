#version 460 core

layout(location = 0) in vec3 aPos; // position variable has attribute 0
layout(location = 1) in vec2 aTexCoord; // texture coordinate variable has attribute 2

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 vColor;    // output color to fragment shader
out vec2 vTexCoord; // output texture coordinate to fragment shader

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    vTexCoord = vec2(aTexCoord.x, aTexCoord.y);
} // end main
