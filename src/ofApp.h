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
	ofImage particleImg1;
	ofMesh quad;
	ofShader shader;
	
	BasicParticleGenerator particleGenerator{};
	ParticleSystem<BasicParticle> particleSystem{particleGenerator, 42, 20.0f};

	void buildMesh(ofMesh& mesh, float w, float h, glm::vec3 pos);
};
