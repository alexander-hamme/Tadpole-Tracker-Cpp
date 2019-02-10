//
// Created by alex on 2/5/19.
//

#ifndef SPROJ_C_ANIMAL_H
#define SPROJ_C_ANIMAL_H
#endif //SPROJ_C_ANIMAL_H

#define DEBUG 1

// this should be high enough to not be a minimum value in a row or col,
// but not high enough that it's worse than giving an assignment a value across the screen
#define DEFAULT_COST_OF_NON_ASSIGNMENT 30.0

#define LINE_THICKNESS 2
#define CIRCLE_RADIUS 15
#define LINE_POINTS_SIZE = 64

#define DATA_BUFFER_ARRAY_SIZE = 60

#include <iostream>

using namespace std;

class Animal {

public:

	Animal(int _x, int _y, int pos_bounds[4], int clr[3]);

	string toString();

	void updateLocation(int _x, int _y, double dt, long timePos);

private:

	int x, y;

	int color[3];
	int position_bounds[4];

	void applyBounds();

	void updateVelocity(double dt);

	//vector<double[]> dataPoints;

	//CircularQueue linePoints; //<int[]>
};

