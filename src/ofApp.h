#pragma once

#include "ofMain.h"
#include "Flower.h"
#include "ofxGifEncoder.h"
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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void addFlower(bool draw);

		vector <Flower> flowers;
		float radius;
		int num;

		ofPolyline center; //center ring
		vector<ofPolyline> rings;
		float rotation;

		ofEasyCam easyCam;

		bool play;

		ofPoint origin;
		Flower currFlower;

		float height;
		float controlHeight;

		int drawRotation;

		ofColor halfTransparency(ofColor);

		ofxGifEncoder gifEncoder;
		float frameW;
		float frameH;
		void captureFrame();
		bool capturing;
		int captureTimer;
		ofImage frame;
};
