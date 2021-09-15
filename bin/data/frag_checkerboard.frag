#version 410

uniform sampler2D parrotTex;
uniform sampler2D checkboardTex;

in vec2 fragUV;
out vec4 outCol;

void main()
{
	vec4 parrot = texture(parrotTex, fragUV);
	vec4 checker = texture(checkboardTex, fragUV);

	//outCol= mix(parrot, checker, 0.5f);
	outCol= mix(parrot, checker, checker.r);
}