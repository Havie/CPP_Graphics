#pragma once

#include "ofMain.h"
#include "ParticleSystem.h"
#include "basicParticle.h"
#include "basicParticleGenerator.h"

class ofApp : public ofBaseApp
{
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

		//MY STUFF
		glm::vec4 NormalizeVector(glm::vec3 pos);


private :
	//ofMesh triangle; //an ofMesh is an vertex buffer "openFramework Mesh"
	ofMesh particleMesh;
	ofShader particleShader;
	ofImage particle1;
	float brightness=0.5f;
	float multiply=1;
	float add=0;
	bool needsReload { true };
	void buildMesh(ofMesh& mesh, float w, float h, glm::vec3 pos);
	void reloadShaders();

	//You can new things up like { int x} instead of =new ClassName(int x)
	//Velocitys shudnt be floats?:
	BasicParticleGenerator particleGenerator { 1,  1,  5, 1,5 };
	ParticleSystem<BasicParticle> particleSystem { particleGenerator, 42, 20.0f };
};
