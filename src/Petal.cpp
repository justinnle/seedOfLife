#include "Petal.h"

Petal::Petal() {

}

Petal::Petal(ofPoint origin, ofPoint top) {
	this -> origin = origin;
	this -> top = top;
}

void Petal::update() {
}

void Petal::draw() {
	line1.draw();
	line2.draw();
}

void Petal::setLine1(ofPath line1, ofPoint l1control1, ofPoint l1control2) {
	this -> line1 = line1;
	this -> l1control1 = l1control1;
	this -> l1control2 = l1control2;
}

void Petal::setLine2(ofPath line2, ofPoint l2control1, ofPoint l2control2) {
	this -> line2 = line2;
	this -> l2control1 = l2control1;
	this -> l2control2 = l2control2;
}

void Petal::setLine(float start, float end, float centerX, float centerY, float radius, float height, bool line) {
	ofPath out;

	start = ofDegToRad(start);
	end = ofDegToRad(end);

	float a = (end - start)/2.0;

	float x4 = radius * cos(a);
	float y4 = radius * sin(a);
	float x1 = x4;
	float y1 = -y4;

	float k = .5522847498; //4/3 * (sqrt(2)-1);
	float f = k * tan(a);
	 
	float x2 = x1 + f * y4;
	float y2 = y1 + f * x4;
	float x3 = x2;
	float y3 = -y2;

	float ar = a + start;
	ofPoint s = ofPoint(radius * cos(start) + centerX		  , radius*sin(start) + centerY);
	ofPoint c1 = ofPoint(x2 * cos(ar) - y2 * sin(ar) + centerX, x2*sin(ar)+y2*cos(ar) + centerY, 0);
	ofPoint c2 = ofPoint(x2*cos(ar)-y3*sin(ar)	+ centerX 	  , x3*sin(ar)+y3*cos(ar) + centerY, 0);
	ofPoint e = ofPoint((radius-height) * cos(end)	+ centerX		  , (radius - height) * sin(end) + centerY, height);

	out.moveTo(s);
	out.bezierTo(c1,c2,e);

	if(line){
		setLine1(out,c1,c2);

	}else{
		setLine2(out,c1,c2);
	}
}

void Petal::setL1Controls(ofPoint c1, ofPoint c2) {
	l1control1 = c1;
	l1control2 = c2;
}

void Petal::setL2Controls(ofPoint c1, ofPoint c2) {
	l2control1 = c1;
	l2control2 = c2;
}

void Petal::setColor(ofColor color) {
	line1.setColor(color);
	line2.setColor(color);
}

void Petal::setFilled(bool hasFill) {
	line1.setFilled(hasFill);
	line2.setFilled(hasFill);
}

void Petal::setStrokeColor(ofColor color) {
	line1.setStrokeColor(color);
	line2.setStrokeColor(color);
}

void Petal::setStrokeWidth(float width) {
	line1.setStrokeWidth(width);
	line2.setStrokeWidth(width);
}