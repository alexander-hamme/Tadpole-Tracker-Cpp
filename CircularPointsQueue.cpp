//
// Created by alex on 2/5/19.
//

#include <iostream>
#include <vector>

using namespace std;

// TODO: make this a struct or enum!
/*class Point {
	public:
		int x,y;
		Point(const int *_x, const int *_y);
};

Point::Point(const int *_x, const int *_y) {
		x = *(_x);
		y = *(_y);
}*/

typedef struct {
	int x;
	int y;
} Point;

/**
 * This class will be used for drawing trailing trajectories
 * using a vector of line points.
 *
 * Accessing the points will be done using a FIFO style traversal
 * from Front backwards to Rear
 */
class CircularPointsQueue {

private:

	//static const int capacity = 30;
	//enum{capacity = 30};

	const unsigned capacity;
	vector<Point> elements;


	// insert elements into array starting at end and working left
	// this allows FIFO traversal by traveling to the right from
	// Front to Rear. (circularly traversing the array)
	unsigned front = capacity-1;

	// stays outside range until the queue reaches full capacity,
	// at which point it is 1 behind front
	unsigned rear = capacity;

public:

	explicit CircularPointsQueue(unsigned cap);

	bool add(Point pt);

	int getFront();
	int getRear();

	void toString();
};

CircularPointsQueue::CircularPointsQueue(unsigned cap)
	: capacity(cap), elements(static_cast<unsigned long>(cap)){
}

/*
 * Adds the given element to this queue. If the queue is full,
 * the least recently added element is discarded
 * so that a new element can be inserted.
 */
bool CircularPointsQueue::add(Point pt) {

	elements.at(front) = pt;

	if (front == 0) {
		front = capacity-1;

	} else {

		front--;

		if (rear == 0) {
			rear = capacity-1;
		} else {
			rear--;
		}
	}

	// todo check for success
	return 0;
}

void CircularPointsQueue::toString() {
	unsigned idx = front;
	while (idx != rear) {
		printf("(%d, %d)", elements.at(idx).x, elements.at(idx).y);
		idx = (idx+1) % capacity;
	}
}

int CircularPointsQueue::getFront() {
	return this->front;
}

int CircularPointsQueue::getRear(){
	return this->rear;
}


