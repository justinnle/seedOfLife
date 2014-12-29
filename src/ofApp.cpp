#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	radius = 75;
	num = 6;
	center.arc(0,0,radius,radius,0,360);
	rotation = 0;
	origin = ofPoint(0,0,0);
	for(int ii = 0; ii < num; ii++) {
		rings.push_back(ofPolyline());
		rings[ii].arc(radius * cos(ofDegToRad(ii*360/num + rotation)),radius * sin(ofDegToRad(ii*360/num + rotation)), radius, radius, 0, 360);
	}
	play = false;
	height = 0;
	currFlower = Flower(origin,radius,num,rotation, 0);
	drawRotation = 90;

	frameW = 540;
	frameH = 540;
	gifEncoder.setup(frameW, frameH, .1, 256);
	captureTimer = 0;
	capturing = false;

}

//--------------------------------------------------------------
void ofApp::update(){
	if(play){
		rotation += 2;
		currFlower.setRotation(rotation);
		if((int)rotation % drawRotation == 0){
			addFlower(true);
		}
	}
	else{
		if((int)rotation % 30 != 0){
			rotation += 2;
		}
	}
	for(int ii=0; ii<flowers.size();ii++){
		flowers[ii].update();
	}
	currFlower.update();
	float arcDeg = 360/num;
	rings.clear();
	for(int ii = 0; ii < num; ii++) {
		rings.push_back(ofPolyline());
		rings[ii].arc(radius * cos(ofDegToRad(ii*360/num + rotation)),radius * sin(ofDegToRad(ii*360/num + rotation)), radius, radius, 0, 360);
	}
	if(capturing){
		captureTimer += 1;
		//cout << captureTimer << "\n";
		if(captureTimer % 5 == 0){
		captureFrame();
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	easyCam.begin();
	ofSetColor(ofColor(127,127,127,127));
		center.draw();
		for(int ii = 0; ii < num; ii++) {
			rings[ii].draw();
		}
		for(int ii=0;ii<flowers.size();ii++){
			if(ii % 2 == 0){
				flowers[ii].setStrokeColor(ofColor::seaGreen);
				//flowers[ii].setColor(halfTransparency(ofColor::seaGreen));
			}else{
				flowers[ii].setStrokeColor(ofColor::navajoWhite);
				//flowers[ii].setColor(halfTransparency(ofColor::najvajoWhite));
				
			}
			flowers[ii].setFilled(false);
			flowers[ii].setStrokeWidth(2);
			flowers[ii].draw();
		}

	easyCam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch(key){
	case 'p':
		play = !play;
		break;
	case 'd':
		addFlower(true);
		break;
	case 'n':
		addFlower(false);
		break;
	case 'q':
		//debugging
		ofLog(OF_LOG_NOTICE) << currFlower.petals[0].line1.getStrokeWidth();
		break;
	case 'b':
		break;
	case ' ':
        captureFrame();
        break;
    case 's':
        cout <<"start saving\n" << endl;
        gifEncoder.save("seedOfLife.gif");
        break;
	case 'c':
		capturing = !capturing;
		if(capturing){
			cout << "capturing on";
		} else {
			cout << "capturing off";
		}

		break;
    default:
		break;
	}

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::addFlower(bool draw) {
	currFlower.drawing = draw;
	flowers.push_back(currFlower);
	radius += 30;
	height = radius/2;
	currFlower = Flower(origin,radius,num,rotation, height);
}

ofColor ofApp::halfTransparency(ofColor color) {
	ofColor c = color;
	c=ofColor(c.r,c.g,c.b,127);
	return c;
}

void ofApp::captureFrame() {
	frame.grabScreen(ofGetWidth()/2-frameW/2, ofGetHeight()/2-frameH/2, frameW, frameH);
	gifEncoder.addFrame(frame);
}
