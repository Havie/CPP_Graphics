#pragma once

#include "ofMain.h"

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
	ofShader shader;
	ofMesh loganMesh;
	ofMesh steveMesh;
	glm::mat4 worldMatrix;

	//x and y coordinates of the mouse from previous frame
	int prevX;
	int prevY;

	//Movement WASD / QE - cam space
	glm::vec3 velocity;
	glm::vec3 position;
	//sensitivity when moving camera with mouse
	float mouseSensitivity = 0.05f;

	//current head direcion of camera
	float cameraHead;
	
	//current pitch direction of camera
	float cameraPitch;

	//near and far variables for camera clip planes
	float cameraClipNear = 0.01f;
	float cameraClipFar = 10.0f;

	//variable for camera field of view
	float FOV = 100.0f;

	//update roations of the camera based on given x y changes
	void updateCameraRotation(float dx, float dy);
};
