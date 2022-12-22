#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;
layout(location = 2) in vec2 TexCoords;

uniform Mat4 projection;
uniform Mat4 model;
uniform Mat4 view;

out vec4 f_color;

void main()
{
	f_color = color;
	// gl_Position = vec4(position); // if you only want to change based on model
	// gl_Position = projection * view * model * vec4(position); // if you want to go 3D
	gl_Position = model * vec4(position); // if you only want to change based on model
	
}