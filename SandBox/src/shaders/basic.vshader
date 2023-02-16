#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;
layout(location = 2) in vec2 TexCoords;

uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;

out vec4 f_color;

void main()
{
	f_color = color;
	gl_Position = projection * view * model * position;
	
}