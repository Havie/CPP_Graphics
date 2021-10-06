#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	loganMesh.load("models/Minecraft_Player.ply");
	steveMesh.load("models/monkeyPez_Trianglar.ply");
	assert(loganMesh.getNumVertices() > 0);
	assert(steveMesh.getNumVertices() > 0);
	shader.load("passthrough.vert", "alphaTest.frag");
	//worldMatrix = glm::translate(glm::vec3(0,0,0));

}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){

	using namespace glm;
	float width = static_cast<float>(ofGetViewportWidth());
	float height = static_cast<float>(ofGetViewportHeight());
	float aspect = width / height;

	mat4 model = translate(vec3(-3, -3, -7)) * rotate(radians(-45.0f), vec3(-0.25, 1, 0.25));
	mat4 view;
	mat4 proj = perspective(radians(100.0f), aspect, 0.01f, 10.0f);

	shader.begin();

	ofEnableDepthTest();
	shader.setUniformMatrix4f("transform", proj * view * model);
	steveMesh.draw();

	model = translate(vec3(3, -2, -6)) * rotate(radians(-45.0f), vec3(0, 1, 0));
	shader.setUniformMatrix4f("transform", proj * view * model);
	loganMesh.draw();
	
	shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
