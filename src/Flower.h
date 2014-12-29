#pragma once

#include "ofMain.h"
#include "Petal.h"

class Flower {
public:
	Flower();
	Flower(ofPoint origin, float radius, int numPetals, float rotation, float maxHeight);

	void update();
	void draw();

	void addPetal(Petal petal);
	void clearPetals();

	void setRotation(float rotation);

	ofPoint origin;
	ofPoint top;
	float radius;
	int numPetals;
	float rotation;
	float height;
	float maxHeight;
	bool drawing;

	vector<Petal> petals;

	void setColor(ofColor color);
	void setFilled(bool hasFill);
	void setStrokeColor(ofColor color);
	void setStrokeWidth(float width);
};