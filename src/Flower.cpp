#include "Flower.h"

Flower::Flower() { 
}

Flower::Flower(ofPoint origin, float radius, int numPetals, float rotation, float maxHeight) {
	this -> origin = origin;
	this -> radius = radius;
	this -> numPetals = numPetals;
	this -> rotation = rotation;
	this -> maxHeight = maxHeight;
	drawing = false;
	height = 0;

	float arcDeg = 360/numPetals;
	for(int ii = 0; ii < numPetals; ii++) {
		petals.push_back(Petal(origin, ofPoint(0,radius,0)));
		petals[ii].setLine((ii + 2) % 6 * arcDeg + rotation,(ii + 1) % 6 * arcDeg + rotation,radius*cos(ofDegToRad((ii + 5) % 6 * arcDeg + rotation)),radius*sin(ofDegToRad((ii + 5) % 6 * arcDeg + rotation)),radius, height, 1);
		petals[ii].setLine((ii + 4) % 6 * arcDeg + rotation,(ii + 5) % 6 * arcDeg + rotation,radius*cos(ofDegToRad((ii + 1) % 6 * arcDeg + rotation)),radius*sin(ofDegToRad((ii + 1) % 6 * arcDeg + rotation)),radius, height, 0);
	}
}

void Flower::update() {
	if(drawing){
		if(height < maxHeight){
			height += 1;
		}
	}
	float arcDeg = 360/numPetals;
	for(int ii = 0; ii < numPetals; ii++) {
		petals[ii].setLine((ii + 2) % 6 * arcDeg + rotation,(ii + 1) % 6 * arcDeg + rotation,radius*cos(ofDegToRad((ii + 5) % 6 * arcDeg + rotation)),radius*sin(ofDegToRad((ii + 5) % 6 * arcDeg + rotation)),radius, height, 1);
		petals[ii].setLine((ii + 4) % 6 * arcDeg + rotation,(ii + 5) % 6 * arcDeg + rotation,radius*cos(ofDegToRad((ii + 1) % 6 * arcDeg + rotation)),radius*sin(ofDegToRad((ii + 1) % 6 * arcDeg + rotation)),radius, height, 0);
	}
}

void Flower::draw() {
	for(int ii = 0; ii < petals.size(); ii++) {
		petals[ii].draw();
	}
}

void Flower::addPetal(Petal petal) {
	if(petals.size() < numPetals){
		petals.push_back(petal);
	}
}

void Flower::clearPetals() {
	petals.clear();
}

void Flower::setRotation(float rotation) {
	this -> rotation = rotation;
}

void Flower::setColor(ofColor color) {
	for(int ii=0; ii < petals.size(); ii++) {
		petals[ii].setColor(color);
	}
}

void Flower::setFilled(bool hasFill) {
	for(int ii=0; ii < petals.size(); ii++) {
		petals[ii].setFilled(hasFill);
	}
}

void Flower::setStrokeColor(ofColor color) {
	for(int ii=0; ii < petals.size(); ii++) {
		petals[ii].setStrokeColor(color);
	}
}

void Flower::setStrokeWidth(float width) {
	for(int ii=0; ii < petals.size(); ii++) {
		petals[ii].setStrokeWidth(width);
	}
}