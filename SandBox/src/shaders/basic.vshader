#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec4 color;

uniform mat4 Transform;

out vec4 f_color;

void main()
{
	gl_Position = Transform * vec4(position, 1.0f);
	f_color = color;
}