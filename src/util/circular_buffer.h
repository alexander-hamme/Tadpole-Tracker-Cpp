//
// Created by alex on 2/7/19.
//

#ifndef SPROJ_CPP_CIRCULARBUFFER_H
#define SPROJ_CPP_CIRCULARBUFFER_H
#endif

#include <vector>

using namespace std;


typedef struct {
	int x;
	int y;
} Point;


class CircularBuffer {

public:

//	explicit CircularBuffer(int cap)   // initialize vector with capacity
//	: capacity(cap), elements(static_cast<unsigned int>(cap)) {};

	CircularBuffer(int cap);

	void add(Point pt);

	int getFront();
	int getRear();
	int getSize();

	bool isAtCapacity();
	bool isEmpty();

	vector<Point> getElements();

	void printPoints();


private:

	const int capacity;

	vector<Point> elements;

	// elements are inserted into array starting at the end,
	// right to left. This allows simple left to right traversal
	// by traveling circularly around the array from `front` to `rear`,
	// while still accessing the elements in FIFO order of insertion.

	int front = capacity;    // this is decremented by 1 before the first insertion

	int rear = capacity-1;   // rear stays at first insertion idx and doesn't change until buffer reaches full capacity

	bool at_capacity = false;

};
