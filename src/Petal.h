#pragma once

#include "ofMain.h"

class Petal {
public:
	Petal();
	Petal(ofPoint origin, ofPoint top);

	void update();
	void draw();

	void setLine1(ofPath line1, ofPoint l1control1, ofPoint l1control2);
	void setLine2(ofPath line2, ofPoint l2control1, ofPoint l2control2);
	
	void setLine(float start, float end, float centerX, float centerY, float radius, float height, bool line);

	void setL1Controls(ofPoint c1, ofPoint c2);
	void setL2Controls(ofPoint c1, ofPoint c2);

	ofPath line1;
	ofPath line2;

	ofPoint l1control1;
	ofPoint l1control2;
	ofPoint l2control1;
	ofPoint l2control2;

	ofPoint origin;
	ofPoint top;

	void setColor(ofColor color);
	void setFilled(bool hasFill);
	void setStrokeColor(ofColor color);
	void setStrokeWidth(float width);
};