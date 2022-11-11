#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;
layout(location = 2) in vec2 TexCoords;

uniform mat4 Transform;

out vec4 f_color;
out vec2 f_TexCoords;

void main()
{
	gl_Position = Transform * position;
	f_color = color;
	f_TexCoords = TexCoords;
}