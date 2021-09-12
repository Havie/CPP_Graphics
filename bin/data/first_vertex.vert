#version 410

int vec3 position; 
out vec4 outColor;

layout (location = 0) in vec3 pos;
layout (location = 1) in vec4 color;
out vec4 fragCol;

void main()
{
	gl_Position = vec4(position, 1.0);
	outColor = vec4(1.0, 0.0, 0.0, 1.0);
	//Where does color magically come from? page 32 book
	fragCol = color;
}

