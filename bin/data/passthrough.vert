#version 410

layout (location = 0) in vec3 pos;
layout (location = 3) in vec2 uv;

uniform vec2 position;
uniform float rotationAmount;

out vec2 fragUV;

void main(){
	vec2 coord = uv;
	float sin_factor = sin(rotationAmount);
	float cos_factor = cos(rotationAmount);
	coord = (coord - 0.5) * mat2(cos_factor, sin_factor, -sin_factor, cos_factor);
	vec3 scale = vec3(0.15, 0.15, 0);
	gl_Position = vec4((pos * scale) + vec3(position, 0), 1.0);

	fragUV = coord + 0.5;

	// good working code
//	vec3 scale = vec3(0.15, 0.15, 0);
//	gl_Position = vec4((pos * scale) + vec3(position, 0), 1.0);
//	fragUV = vec2(uv.x, 1.0-uv.y);
}