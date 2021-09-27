#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofDisableArbTex();

	buildMesh(lightMesh, 1.0, 1.0, glm::vec3(0.0, 0.0, 0.0));
	buildMesh(smokeMesh, 1.0, 1.0, glm::vec3(0.0, 0.0, 0.0));
	shader.load("passthrough.vert", "colorChange.frag");
	//load light flare imgs
	particleImg1.load("textures/magic_01.png");
	particleImg2.load("textures/magic_02.png");
	particleImg3.load("textures/magic_03.png");
	particleImg4.load("textures/magic_04.png");
	particleImg5.load("textures/magic_05.png");
	//load smoke imgs
	/*smokeImages[0].load("textures/smoke_01.png");
	smokeImages[1].load("textures/smoke_02.png");
	smokeImages[2].load("textures/smoke_03.png");
	smokeImages[3].load("textures/smoke_04.png");
	smokeImages[4].load("textures/smoke_05.png");
	smokeImages[5].load("textures/smoke_06.png");
	smokeImages[6].load("textures/smoke_07.png");
	smokeImages[7].load("textures/smoke_08.png");
	smokeImages[8].load("textures/smoke_09.png");
	smokeImages[9].load("textures/smoke_10.png");*/

	smokeImages[0].load("textures/twirl_01.png");
	smokeImages[1].load("textures/twirl_02.png");
	smokeImages[2].load("textures/twirl_03.png");
	smokeImages[3].load("textures/twirl_01.png");
	smokeImages[4].load("textures/twirl_02.png");
	smokeImages[5].load("textures/twirl_03.png");
	smokeImages[6].load("textures/twirl_01.png");
	smokeImages[7].load("textures/twirl_02.png");
	smokeImages[8].load("textures/twirl_03.png");
	smokeImages[9].load("textures/twirl_01.png");

}

//--------------------------------------------------------------
void ofApp::update(){
	float dt = ofGetLastFrameTime();
	rotationAmount -= 3 * dt;
	if (rotationAmount < -360) {
		rotationAmount = 0;
	}
	particleSystem.update(dt);
	smokeSystem.update(dt);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	shader.begin();
	
	//particleSystem drawing
	for (const BasicParticle p : particleSystem) {
		
		shader.setUniform2f("position", p.getPosition());
		shader.setUniform1f("life", p.getLife());
		shader.setUniform1f("rotationAmount", rotationAmount * 2);
		shader.setUniform4f("color", glm::vec4(1.0, 1.0, 0.5, 1.0));

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
		lightMesh.draw();
	}
	ofDisableBlendMode();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	for (const BasicParticle s : smokeSystem) {

		int arrSize = sizeof(smokeImages) / sizeof(smokeImages[0]);
		int index = (rand() % arrSize);
		shader.setUniformTexture("particle", smokeImages[index], 0);
		shader.setUniform2f("position", s.getPosition());
		shader.setUniform1f("life", s.getLife());
		shader.setUniform1f("rotationAmount", rotationAmount);
		shader.setUniform4f("color", glm::vec4(.5, .5, .5, 0.5f));

		/*std::cout << "Velocity: " << s.getVelocity() << "\n";
		std::cout << "Position: " << s.getPosition() << "\n";*/
		smokeMesh.draw();
	}

	ofDisableBlendMode();
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
