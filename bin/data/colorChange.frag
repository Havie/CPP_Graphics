#version 410
uniform sampler2D particle;
in vec2 fragUV;

out vec4 outCol;

void main(){
	outCol = texture(particle, fragUV) * vec4(1.0, 1.0, 0.5, 1.0);
}