//
// Created by alex on 2/5/19.
//

#include <iostream>
#include <vector>
#include "CircularPointsQueue.h"

using namespace std;


/*
 * Adds the given element to the queue. If the queue is full,
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

	// at() has automatic bounds checking, as opposed to using the [] operator
	elements.at(static_cast<unsigned int>(front)) = pt;

	cout << endl;

	// todo check for success
	return true;
}

vector<Point> CircularPointsQueue::getElements() {
	return this->elements;
}

int CircularPointsQueue::getSize() {
	return this->capacity;
}

bool CircularPointsQueue::isAtCapacity() {
	return this->atCapacity;
}

bool CircularPointsQueue::isEmpty() {
	return this->elements.empty();
}

int CircularPointsQueue::getFront() {
	return this->front;
}

int CircularPointsQueue::getRear() {
	return this->rear;
}


/*
 * Print out elements in FIFO order
 */
void CircularPointsQueue::toString() {

	auto idx = static_cast<unsigned int>(front);

	cout << "Elements:\t[";

	if (! atCapacity) {

		while(idx <= rear) {

			printf("(%d,%d)", elements.at(idx).x, elements.at(idx).y);

			if (idx != rear) {
				cout << ", ";
			}

			idx++;
		}

	} else {

		while (idx != rear) {

			printf("(%d,%d)", elements.at(idx).x, elements.at(idx).y);

			if (idx != rear) {
				cout << ", ";
			}

			idx = (idx + 1) % capacity;

			if (idx == rear) {
				printf("(%d,%d)", elements.at(idx).x, elements.at(idx).y);
				break;
			}
		}
	}
	cout << "]" << endl;
}