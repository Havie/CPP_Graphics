//a shader that sends UVs to the fragment shadercallcoherent
#version 410
layout (location =0) in vec3 pos;
layout (location =3) in vec2 uv;

out vec2 fragUV;

void main()
{
	gl_Position = vec4(pos, 1.0);
	//fragUV = uv;
	//Flip the y for the img becuz
	fragUV = vec2(uv.x, 1.0 - uv.y);
}

/*
By default openFrameworks assigns vertex attr to following locations
1.pos
2.color
3.normal
4.UV coords
*/












