#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;
layout(location = 2) in vec2 TexCoords;

uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;

out vec4 f_color;
out vec2 f_texCoords;

void main()
{
	f_color = color;
	f_texCoords = TexCoords;
	gl_Position = position * projection;
	gl_Position = projection * model * position;
	gl_Position = projection * view * model * position;
}