#version 330 core 

out vec4 color;

in vec4 f_color;
in vec2 f_texCoords;

uniform sampler2D Texture0;

void main()
{
	// color = vec4(1.0,0.0,0.0, 1.0);
	color = texture(Texture0, f_texCoords);
   
}	