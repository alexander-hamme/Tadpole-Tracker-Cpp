//
// Created by alex on 2/5/19.
//

#include <iostream>
#include <vector>

#include "animal.h"
//#include "CircularBuffer.h"

using namespace std;

Animal::Animal(int x, int y, int pos_bounds[4], int clr[3]) {
	x_pos = x;
	y_pos = y;
	color = clr;
	position_bounds = pos_bounds;
	curr_cost_non_assignment = default_cost_non_assignment;
}

void Animal::updateLocation(int _x, int _y, double dt, long time_pos) {
	x_pos = _x;
	y_pos = _y;

	applyBounds();

	const double new_pt[3] = {(double) time_pos, (double) x_pos, (double) y_pos};

	data_points.push_back(new_pt);

	Point pt{x_pos, y_pos};

	line_points_q.add(pt);
	//line_points_q.add(Point {x_pos, y_pos});
}


void Animal::updateVelocity(double dt, int frame_numb) {

	int subtractionIdx = 3;  // calculate velocity over the last N frames

	if (frame_numb < subtractionIdx + 1) {
		vx = 0;
		vy = 0;

	} else {

		//todo calculate average velocity across several previous points?

		// the most recent point is at the end, then subtract subtractionIdx from there
		double *prev_point = data_points.at(data_points.size() - 1 - subtractionIdx);

		this->vx = (this->x_pos - (int) prev_point[1]) / (subtractionIdx * dt);

		// flip the subtraction because y axis in graphics increases down instead of up
		this->vy = ((prev_point[1] - this->y_pos) / (subtractionIdx * dt));
	}

}

/**
 * Constrains current position to coordinate bounds declared in construction
 */
void Animal::applyBounds() {
	x_pos = (x_pos > position_bounds[0]) ? x_pos : position_bounds[0];
	x_pos = (x_pos < position_bounds[1]) ? x_pos : position_bounds[1];
	y_pos = (y_pos > position_bounds[2]) ? y_pos : position_bounds[2];
	y_pos = (y_pos < position_bounds[3]) ? y_pos : position_bounds[3];
}


double Animal::getCurrCost() {
	return curr_cost_non_assignment;
}

void Animal::setCurrCost(const double val) {
	curr_cost_non_assignment = val;
}

/**
 * TODO: replace this functionality with something more efficient
 */
void Animal::clearPoints() {
	data_points.clear();
}
