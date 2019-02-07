//
// Created by alex on 2/7/19.
//

#ifndef SPROJ_CPP_CIRCULARPOINTSQUEUE_H
#define SPROJ_CPP_CIRCULARPOINTSQUEUE_H

#endif //SPROJ_CPP_CIRCULARPOINTSQUEUE_H


#include <vector>

using namespace std;

typedef struct {
	int x;
	int y;
} Point;


class CircularPointsQueue {

private:

	//static const int capacity = 30;
	//enum{capacity = 30};

	const unsigned capacity;
	vector<Point> elements;


	// insert elements into array starting at end and working left
	// this allows FIFO traversal by traveling to the right from
	// Front to Rear. (circularly traversing the array)
	unsigned front = capacity;

	// stays outside range until the queue reaches full capacity,
	// at which point it is 1 behind front
	unsigned rear = capacity-1;


	bool atCapacity = false;

public:

	explicit CircularPointsQueue(unsigned cap): capacity(cap), elements(static_cast<unsigned long>(cap))
	{
	};

	bool add(Point pt);

	int getFront();
	int getRear();

	void toString();
};