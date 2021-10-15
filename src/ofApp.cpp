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

void ofApp::updateCameraRotation(float dx, float dy) {
	cameraHead += dx;
	cameraPitch += dy;
}

//--------------------------------------------------------------
void ofApp::update()
{
	using namespace glm;
	//Do the opposite/Inverse of the view matrix to calculate world space velo
	vec3 velocityWorldSpace = mat3((rotate(-cameraHead, vec3(0, 1, 0)) * rotate(-cameraPitch, vec3(1, 0, 0)))) * velocity;

	float dt = static_cast<float>(ofGetLastFrameTime());
	position += velocityWorldSpace * dt;

}

//--------------------------------------------------------------
void ofApp::draw(){

	using namespace glm;
	float width = static_cast<float>(ofGetViewportWidth());
	float height = static_cast<float>(ofGetViewportHeight());
	float aspect = width / height;

	//changes to model position
	mat4 model = translate(vec3(-3, -3, -7)) * rotate(radians(-45.0f), vec3(-0.25, 1, 0.25));
	//changes to camera position, head rotates around y axis, pitch rotates around x axis
	mat4 view = (rotate(cameraPitch, vec3(1, 0, 0)) * rotate(cameraHead, vec3(0,1,0)) * translate(-position));
	//sets perspective type and near/far camera clip planes
	mat4 proj = perspective(radians(FOV), aspect, cameraClipNear, cameraClipFar);

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
	//z-axis	
	if (key== 'w')
	{
		velocity.z = -1;
	}
	else if (key== 's')
	{
		velocity.z = 1;
	}
	//x-axis
	else if (key== 'a')
	{
		velocity.x = -1;
	}
	else if (key== 'd')
	{
		velocity.x = 1;
	}
	//Y-axis
	else if (key== 'q')
	{
		velocity.y = -1;
	}
	else if (key== 'e')
	{
		velocity.y = 1;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

	//z-axis	
	if (key== 'w' || key== 's')
	{
		velocity.z = 0;
	}
	//x-axis	
	if (key== 'a' || key== 'd')
	{
		velocity.x = 0;
	}
	//y-axis	
	if (key== 'q' || key== 'e')
	{
		velocity.y = 0;
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	if (prevX != 0 && prevY != 0) {
		updateCameraRotation(mouseSensitivity * (x - prevX), mouseSensitivity * (y - prevY));
	}
	prevX = x;
	prevY = y;
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
