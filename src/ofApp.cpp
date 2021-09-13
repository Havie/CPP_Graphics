#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	brightness = 0.5f;
	//quad.addVertex(glm::vec3(0.0, 0.0, 0.0));
	//quad.addVertex(glm::vec3(0.0, 768.0, 0.0));
	//quad.addVertex(glm::vec3(1024.0, 768.0, 0.0));

	quad.addVertex(glm::vec3(-1, -1, 0));
	quad.addVertex(glm::vec3(-1, 1, 0));
	quad.addVertex(glm::vec3(1, 1, 0));
	quad.addVertex(glm::vec3(1, -1, 0));

	
	quad.addColor(ofDefaultColorType(1, 0, 0, 1)); //red
	quad.addColor(ofDefaultColorType(0, 1, 0, 1)); //green
	quad.addColor(ofDefaultColorType(0, 0, 1, 1)); //blue
	quad.addColor(ofDefaultColorType(1, 1, 1, 1)); //white

	
	//UV coords start at bot left of an image and increase towards top.
	//Let this quad have textures (UV)
	quad.addTexCoord(glm::vec2(0, 0));
	quad.addTexCoord(glm::vec2(0, 1));
	quad.addTexCoord(glm::vec2(1, 1));
	quad.addTexCoord(glm::vec2(1, 0));

		//for the faces?
	ofIndexType indicies[6] = { 0,1,2,2,3,0 };
	quad.addIndices(indicies, 6);

	
	shader.load("uv_scrolling.vert", "texture.frag");
	//Get in a new tex
	ofDisableArbTex();
	img.load("parrot.png");
	//Allow us to access tex with >1 coord vals, 1.25 will wrap to 0.25
	img.getTexture().setTextureWrap(GL_REPEAT, GL_REPEAT);
}


//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{
	//begin the shader
	shader.begin();
	//has to be after shader begin , places a global var on all process steps
	//shader.setUniform4f("fragCol", glm::vec4(0, 1, 1, 1));
	shader.setUniformTexture("parrotTex",img , 0);
	//Give our shader the ability to tick/scroll based on time
	shader.setUniform1f("time", ofGetElapsedTimef());
	shader.setUniform1f("brightness", brightness);
	//of takes care of passing this to the graphics buffer
	quad.draw();
	//end the shader-must do 
	shader.end();

	//ofSetBackgroundColor(ofColor::azure);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	glm::vec3 curPos = quad.getVertex(2);
	quad.setVertex(2, curPos + glm::vec3(0, -1, 0 ));
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

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