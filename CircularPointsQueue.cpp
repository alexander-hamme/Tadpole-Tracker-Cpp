//
// Created by alex on 2/5/19.
//

#include <iostream>
#include <vector>
#include "CircularPointsQueue.h"

using namespace std;

/**
 * This class will be used for drawing trailing trajectories
 * using a vector of line points.
 *
 * Accessing the points will be done using a FIFO style traversal
 * from Front backwards to Rear
 */

/*
CircularPointsQueue::CircularPointsQueue(unsigned cap)
	: capacity(cap), elements(static_cast<unsigned long>(cap)){
}*/

/*
 * Adds the given element to this queue. If the queue is full,
 * the least recently added element is discarded
 * so that a new element can be inserted.
 */
bool CircularPointsQueue::add(Point pt) {

	//cout << boost::format("%d") % front;
	//printf("Front is %d", front);

	if (front == 0) {

		// this stays true once queue reaches capacity for the first time
		atCapacity = true;

		front = capacity - 1;
		rear = capacity - 2;

	} else {

		front--;

		if (atCapacity) {

			if (rear == 0) {

				rear = capacity - 1;

			} else {
				rear--;
			}
		}
	}

	std::cout << "Front is " << front << std::endl;
	std::cout << "Rear is " << rear << std::endl;

	elements.at(front) = pt;


	this->toString();

	cout << endl;

	// todo check for success
	return false;
}

void CircularPointsQueue::toString() {

	unsigned idx = front;

	cout << "Elements:\t";

	if (! atCapacity) {
		while(idx <= rear) {
			printf("(%d,%d)\t", elements.at(idx).x, elements.at(idx).y);
			idx++;
		}
	} else {

		while (idx != rear) {
			//std::cout << "Idx is " << idx << "\t";

			printf("(%d,%d)\t", elements.at(idx).x, elements.at(idx).y);
			idx = (idx + 1) % capacity;

			if (idx == rear) {
				printf("(%d,%d)\t", elements.at(idx).x, elements.at(idx).y);
				break;
			}
		}
	}
	cout << endl;
}

int CircularPointsQueue::getFront() {
	return this->front;
}

int CircularPointsQueue::getRear() {
	return this->rear;
}


