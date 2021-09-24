#version 410
uniform sampler2D particle;
uniform float life;
uniform vec4 color;
in vec2 fragUV;

out vec4 outCol;

void main(){
	outCol = texture(particle, fragUV) * color * (1-life);
}