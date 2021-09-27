#pragma once

#include "ofMain.h"
#include "BasicParticleGenerator.h"
#include "ParticleSystem.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
private:
	float rotationAmount;
	ofImage particleImg1;
	ofImage particleImg2;
	ofImage particleImg3;
	ofImage particleImg4;
	ofImage particleImg5;
	ofImage smokeImages[10];
	ofMesh lightMesh;
	ofMesh smokeMesh;
	ofShader shader;
				//(float life, float minSize, float maxSize, glm::vec2 minVelo, glm::vec2 maxVelo, float xPosVariance, float yPosVariance);
	BasicParticleGenerator particleGenerator { 1,  1, 2,  glm::vec2(-1,-1),glm::vec2(1,1) , .5, .5};
	BasicParticleGenerator smokeGenerator { 1,  2, 4,  glm::vec2(0,0),glm::vec2(0,1), .1, .1 };
	ParticleSystem<BasicParticle> particleSystem{particleGenerator, 42, 20.0f};
	ParticleSystem<BasicParticle> smokeSystem{smokeGenerator, 21, 10.0f};

	

	void buildMesh(ofMesh& mesh, float w, float h, glm::vec3 pos);
};
