#pragma once

#include "ofMain.h"

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
	ofMesh quad;
	ofShader shader;
	ofImage img;
	ofImage img2;
	float brightness=0.5f;
	float multiply=1;
	float add=0;
		
};
