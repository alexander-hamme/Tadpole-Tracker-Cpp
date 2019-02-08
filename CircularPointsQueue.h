//
// Created by alex on 2/7/19.
//

#ifndef SPROJ_CPP_CIRCULARPOINTSQUEUE_H
#define SPROJ_CPP_CIRCULARPOINTSQUEUE_H
#endif

#include <vector>

using namespace std;


typedef struct {
	int x;
	int y;
} Point;

/**
 * This class will be used for drawing trailing trajectories
 * in a graphics window using a vector of line points.
 *
 * Accessing the points will be done with a First In First Out (FIFO)
 * style traversal from `front` circularly around the array
 * until it reaches `rear`
 */
class CircularPointsQueue {

private:

	const int capacity;

	vector<Point> elements;

	// elements will be inserted into array starting at the end,
	// right to left. This allows simple FIFO traversal by traversing
	// circularly around the array from `front` to `rear`.

	int front = capacity;    // this is decremented by 1 before first insertion

	int rear = capacity-1;   // rear stays at first insertion until queue reaches full capacity

	bool atCapacity = false;

public:

	explicit CircularPointsQueue(int cap)   // initialize vector with capacity
	: capacity(cap), elements(static_cast<unsigned int>(cap)) {};

	bool add(Point pt);

	int getFront();
	int getRear();
	int getSize();

	bool isAtCapacity();
	bool isEmpty();

	vector<Point> getElements();

	void toString();
};