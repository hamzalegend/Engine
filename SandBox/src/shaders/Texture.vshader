#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;
layout(location = 2) in vec2 TexCoords;

uniform mat4 projection;
uniform mat4 model;
uniform mat4 view;

out vec4 f_color;
out vec2 f_texCoords;

void main()
{
	// move stuff to fragment shader
		f_color = color;
		f_texCoords = TexCoords;

	// actual vertex computing
		gl_Position = vec4(position) * model * projection; 
		gl_Position = projection * view * model * vec4(position); // if you want to go 3D
		gl_Position = model * vec4(position); // if you only want to change based on model
}

