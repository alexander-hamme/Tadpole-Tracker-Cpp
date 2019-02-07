//
// Created by alex on 2/5/19.
//

#include "Animal.h"
//#include "CircularPointsQueue.cpp"

#include <iostream>
#include <vector>

using namespace std;

class Animal {

	public:

		Animal(int _x, int _y, int pos_bounds[], int clr[]);

		string toString();

		void updateLocation(int _x, int _y, double dt, long timePos);


	private:

		void applyBounds();

		void updateVelocity(double dt);

		vector<double[]> dataPoints;

		//CircularPointsQueue linePoints; //<int[]>


};

/*
 *
 * public Animal(int _x, int _y, final int[] positionBounds, final Scalar clr, KalmanFilter kFilter) {
        this.x = _x; this.y = _y;
        this.positionBounds = positionBounds;
        currentHeading = 0;
        color = clr; // new Scalar(clr[0], clr[1], clr[2], 1.0);
        linePoints = new CircularPointsQueue<>(LINE_POINTS_SIZE);
        dataPoints = new ArrayList<>(DATA_BUFFER_ARRAY_SIZE);
        trackingFilter = kFilter;

        this.timeStepsPredicted = 0;
        this.currCostNonAssignnmnt = DEFAULT_COST_OF_NON_ASSIGNMENT;
}
 */