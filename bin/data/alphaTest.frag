#version 410

//defined in ofApp.draw() charShader.setUniformTexture("greenMan",alienImg , 0);
uniform sampler2D greenMan;
in vec2 fragUV;
//If u only have one out, u can name it whatever, otherwise use the location = # system
out vec4 outColor;

void main()
{
	outColor = texture(greenMan, fragUV);
	if(outColor.a < 1.0f)
		discard;
}