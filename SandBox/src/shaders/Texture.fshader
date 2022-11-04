#version 330 core 

out vec4 color;

in vec4 f_color;

void main()
{
   // color = vec4(1.0,0.0,0.0, 1.0);
   color = f_color;
}
