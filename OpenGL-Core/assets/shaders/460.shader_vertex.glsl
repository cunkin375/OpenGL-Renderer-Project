#version 460 core

layout(location = 0) in vec3 aPos; // position variable has attribute 0
layout(location = 2) in vec2 aTexCoord; // texture coordinate variable has attribute 2

out vec3 vColor; // output color to fragment shader
out vec2 vTexCoord; // output texture coordinate to fragment shader

uniform mat4 uTransform;

void main()
{
    gl_Position = uTransform * vec4(aPos, 1.0);
    vTexCoord = vec2(aTexCoord.x, aTexCoord.y);
} // end main
