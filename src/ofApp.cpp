#include "ofApp.h"
#include "basicParticle.h"
#include "basicParticleGenerator.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	buildMesh(particleMesh, 0.25, 0.5, glm::vec3(0.0f, 0.15f, 0.0f));
	reloadShaders();
	//Get in a new tex
	ofDisableArbTex();
	particle1.load("textures/circle_01.png");
	//Allow us to access tex with >1 coord vals, 1.25 will wrap to 0.25
	particle1.getTexture().setTextureWrap(GL_REPEAT, GL_REPEAT);
}

//--------------------------------------------------------------
void ofApp::buildMesh(ofMesh& mesh, float w, float h, glm::vec3 pos)
{
	float verts[] = 
	{
		-w + pos.x, -h + pos.y, pos.z,
		-w + pos.x, h + pos.y, pos.z,
		w + pos.x, h + pos.y, pos.z,
		w + pos.x, -h + pos.y, pos.z };

	float uvs[] = { 0,0, 0,1, 1,1, 1,0 };

	for ( int i = 0; i < 4; ++i )
	{
		//index
		int idx = i * 3;
		//uv index
		int uvIdx = i * 2;

		mesh.addVertex(glm::vec3(verts[idx], verts[idx + 1], verts[idx + 2]));
		mesh.addTexCoord(glm::vec2(uvs[uvIdx], uvs[uvIdx + 1]));

		ofIndexType indices[6] = { 0,1,2,2,3,0 };
		mesh.addIndices(indices, 6);
	}
}

//--------------------------------------------------------------
void ofApp::reloadShaders()
{
	particleShader.load("uv_passthrough.vert", "alphaTest.frag");
	needsReload = false;
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofSetBackgroundColor(ofColor::black);

	//draw the particles
	particleShader.begin();
	//make it a ref so its not a copy 
	for (const BasicParticle& p : particleSystem )
	{
		particleShader.setUniform2f("particlePosition", p.getPos());
		particleShader.setUniform1f("particleSize", p.getSize());
		//etc
		particleMesh.draw();
	}

	particleShader.end();

}

//--------------------------------------------------------------
void ofApp::update()
{
	if ( needsReload )
	{
		reloadShaders();
	}

	particleSystem.update(ofGetLastFrameTime());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	glm::vec3 curPos = particleMesh.getVertex(2);
	particleMesh.setVertex(2, curPos + glm::vec3(0, -1, 0 ));
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
	if ( key == '`' )
	{
		//reload shaders
		needsReload = true;
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}
//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}

//--------------------------------------------------------------
glm::vec4 NormalizeVector(glm::vec3 pos)
{
	float x = (pos.x / 1024.0) * 2.0 - 1.0;
	float y = (pos.y / 768.0) * 2.0 - 1.0;
	return glm::vec4(x, y, 0.0, 1.0);
}