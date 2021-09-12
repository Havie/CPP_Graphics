#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	triangle.addVertex(glm::vec3(0.0, 0.0, 0.0));
	triangle.addVertex(glm::vec3(0.0, 768.0, 0.0));
	triangle.addVertex(glm::vec3(1024.0, 768.0, 0.0));
	/*
	triangle.addVertex(glm::vec3(0.0, 0.0, 0.0));
	triangle.addVertex(glm::vec3(0.0, 768.0, 0.0));
	triangle.addVertex(glm::vec3(1024.0, 768.0, 0.0));
	
	triangle.addColor(ofFloatColor(1.0f,0.0f,0.0f,1.0f));
	triangle.addColor(ofFloatColor(0.0f,1.0f,0.0f,1.0f));
	triangle.addColor(ofFloatColor(0.0f,0.0f,1.0f,1.0f));
	
	*/
	shader.load("first_vertex.vert", "first_fragment.frag");
}

glm::vec4 NormalizeVector(glm::vec3 pos)
{
	float x = (pos.x / 1024.0) * 2.0 - 1.0;
	float y = (pos.y / 768.0) * 2.0 - 1.0;
	return glm::vec4(x, y, 0.0, 1.0);
}

//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{
	shader.begin();
	//of takes care of passing this to the graphics buffer
	triangle.draw();
	shader.end();

	//ofSetBackgroundColor(ofColor::azure);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	glm::vec3 curPos = triangle.getVertex(2);
	triangle.setVertex(2, curPos + glm::vec3(0, 20, 0 ));
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
