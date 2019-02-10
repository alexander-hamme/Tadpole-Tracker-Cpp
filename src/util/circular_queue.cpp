//
// Created by alex on 2/5/19.
//

#include <iostream>
#include <vector>
#include "circular_queue.h"

using namespace std;


/*
 * Adds the given element to the queue. If the queue is full,
 * the least recently added element is discarded
 * so that a new element can be inserted.
 */
void CircularQueue::add(Point pt) {

	//cout << boost::format("%d") % front;
	//printf("Front is %d", front);

	if (front == 0) {

		at_capacity = true;  // this stays true once queue reaches capacity for the first time,
							// because deleting or popping elements from the line points queue is not supported

		front = capacity - 1;
		rear = capacity - 2;

	} else {

		front--;

		if (at_capacity) {

			if (rear == 0) {

				rear = capacity - 1;

			} else {
				rear--;
			}
		}
	}

//	std::cout << "Front is " << front << std::endl;
//	std::cout << "Rear is " << rear << std::endl;

	// at() has automatic bounds checking, as opposed to using the [] operator
	elements.at(static_cast<unsigned int>(front)) = pt;

	// todo check for success?
}

vector<Point> CircularQueue::getElements() {
	return this->elements;
}

int CircularQueue::getSize() {
	return (at_capacity) ? this->capacity : (rear+1 - front);
}

bool CircularQueue::isAtCapacity() {
	return this->at_capacity;
}

bool CircularQueue::isEmpty() {
	return this->elements.empty();
}

int CircularQueue::getFront() {
	return this->front;
}

int CircularQueue::getRear() {
	return this->rear;
}


/*
 * Print out elements in FIFO order
 */
void CircularQueue::printPoints() {

	auto idx = static_cast<unsigned int>(front);

	cout << "Elements:\t[";

	// if queue is not at capacity, FIFO traversal is simple,
	// because elements are inserted in reverse order into the array.
	// Accessing elements in FIFO order is done by incrementing `front` to `rear`
	if (! at_capacity) {

		while(idx <= rear) {

			printf("(%d,%d)", elements.at(idx).x, elements.at(idx).y);

			if (idx != rear) {
				cout << ", ";
			}

			idx++;
		}

	} else {

		// if queue is at capacity, `front` is incremented circularly around
		// the array until it reaches `rear`.

		// one extra check must be included for when front reaches
		// (is equal to) rear, because rear is always at the last element
		// (in FIFO order) in the array
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