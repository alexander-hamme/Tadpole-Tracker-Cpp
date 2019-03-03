//
// Created by alex on 2/5/19.
//

#include <iostream>
#include <vector>
#include "circular_buffer.h"

using namespace std;


/*
 * TODO: make an iterator that yields elements in order from front to rear
 */


/**
 * This class is intended to be used for drawing trailing line trajectories
 * in a graphics window using a vector of line points. Each instance of the
 * Animal class receives its own CircularBuffer instance to store its trajectory.
 *
 * Using a cyclic buffer instead of a normal vector allows the same memory
 * block to be reused for the duration of the tracker system's runtime.
 *
 * The points are accessed in First In First Out (FIFO) order
 * by traversing from `front` circularly around the array
 * until it reaches `rear`.
 */
CircularBuffer::CircularBuffer(int cap)   // initialize vector with capacity
		: capacity(cap), elements(static_cast<unsigned int>(cap)) {};


/*
 * Adds the given element to the buffer. If the buffer is full,
 * the least recently added element is discarded
 * so that a new element can be inserted.
 *
 * Note that in this implementation, elements are added to the array
 * starting at the END, and then inserting right to left.
 *
 * This makes iterating through all the elements in FIFO order of insertion
 * very easy with a simple left to right traversal, traveling circularly
 * around the array from `front` to `rear`.
 */
void CircularBuffer::add(Point pt) {

	//cout << boost::format("%d") % front;
	//printf("Front is %d", front);

	if (front == 0) {

		at_capacity = true;  // this stays true once buffer reaches capacity for the first time
		                     // (deleting or popping elements from the buffer is not supported)
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

	// at() has automatic bounds checking, as opposed to using the [] operator
	elements.at(static_cast<unsigned int>(front)) = pt;

	// todo check for success?
}

vector<Point> CircularBuffer::getElements() {
	return this->elements;
}

int CircularBuffer::getSize() {
	return (at_capacity) ? this->capacity : (rear+1 - front);
}

bool CircularBuffer::isAtCapacity() {
	return this->at_capacity;
}

bool CircularBuffer::isEmpty() {
	return this->elements.empty();
}

int CircularBuffer::getFront() {
	return this->front;
}

int CircularBuffer::getRear() {
	return this->rear;
}


/*
 * Print out elements in FIFO order
 */
void CircularBuffer::printPoints() {

	auto idx = static_cast<unsigned int>(front);

	cout << "Elements:\t[";

	// if buffer is not at capacity, FIFO traversal is simple,
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

		// if buffer is at capacity, `front` is incremented circularly around
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
