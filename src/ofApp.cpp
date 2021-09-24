#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofDisableArbTex();

	buildMesh(quad, 1.0, 1.0, glm::vec3(0.0, 0.0, 0.0));
	shader.load("passthrough.vert", "colorChange.frag");

	particleImg1.load("textures/magic_01.png");
	particleImg2.load("textures/magic_02.png");
	particleImg3.load("textures/magic_03.png");
	particleImg4.load("textures/magic_04.png");
	particleImg5.load("textures/magic_05.png");
}

//--------------------------------------------------------------
void ofApp::update(){
	particleSystem.update(ofGetLastFrameTime());
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	shader.begin();
	

	//particleSystem drawing
	for (const BasicParticle p : particleSystem) {
		shader.setUniform2f("position", p.getPosition());
		shader.setUniform1f("life", p.getLife());
		if (p.getLife() > 0.9 && p.getLife() != 1) {
			shader.setUniformTexture("particle", particleImg1, 0);
		} else if (p.getLife() > 0.8) {
			shader.setUniformTexture("particle", particleImg2, 0);
		} else if (p.getLife() > 0.7) {
			shader.setUniformTexture("particle", particleImg3, 0);
		} else if (p.getLife() > 0.55) {
			shader.setUniformTexture("particle", particleImg4, 0);
		} else {
			shader.setUniformTexture("particle", particleImg5, 0);
		}
		//std::cout << "Position: " << p.getPosition() << "\n";
		quad.draw();
	}


	shader.end();
	ofDisableBlendMode();
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

void ofApp::buildMesh(ofMesh& mesh, float w, float h, glm::vec3 pos) {
	float verts[] = {
		-w + pos.x, -h + pos.y, pos.z,
		-w + pos.x, h + pos.y, pos.z,
		w + pos.x, h + pos.y, pos.z,
		w + pos.x, -h + pos.y, pos.z };

	float uvs[] = { 0,0, 0,1, 1,1, 1,0 };

	for (int i = 0; i < 4; ++i) {
		int idx = i * 3;
		int uvIdx = i * 2;

		mesh.addVertex(glm::vec3(verts[idx], verts[idx + 1], verts[idx + 2]));
		mesh.addTexCoord(glm::vec2(uvs[uvIdx], uvs[uvIdx + 1]));

		ofIndexType indices[6] = { 0,1,2,2,3,0 };
		mesh.addIndices(indices, 6);
	}
}
