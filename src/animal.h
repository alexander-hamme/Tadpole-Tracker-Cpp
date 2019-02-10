//
// Created by alex on 2/5/19.
//

#ifndef SPROJ_C_ANIMAL_H
#define SPROJ_C_ANIMAL_H
#endif

#include <iostream>
#include "util/circular_buffer.h"


using namespace std;


/**
 * Class used to record the motion data of individual
 * subject animals during tracking
 */
class Animal {

public:

	Animal(int x, int y, int pos_bounds[4], int clr[3]);

	void updateLocation(int _x, int _y, double dt, long time_pos);

	int *getColor();

	int getX() {return this->x_pos;}
	int getY() {return this->y_pos;}

	double getCurrCost();

	void setCurrCost(const double val);

	string toString();

private:

	// this should be high enough to not be a minimum value in a row or col,
	// but not high enough that it's worse than giving an assignment a value across the screen
	const double default_cost_non_assignment = 30.0;

	const size_t line_thickness = 2;
	const size_t circle_radius = 15;
	const size_t data_array_size = 60;
	const int line_points_size = 64;

	int x_pos, y_pos;
	double vx, vy;

	int* color;

	int* position_bounds;  // x1  x2  y1  y2

	double curr_cost_non_assignment;

	void applyBounds();

	void updateVelocity(double dt, int frame_numb);

	void clearPoints();

	vector<double[3]> data_points;

	CircularBuffer line_points_q = CircularBuffer(line_points_size);

};

