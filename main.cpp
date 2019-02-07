#include <iostream>

#include "CircularPointsQueue.h"


int main() {

	std::cout << "Hello, World!" << std::endl;

	// auto assumes type  (since c++11)
	auto *pointsQueue = new CircularPointsQueue(5);

	// todo: have to change the values that the pointer points too,
	// not try to create new objects!


	Point pt;

	for (int i=0; i<10; i++) {
		pt.x = i;
		pt.y = i;
		pointsQueue->add(pt);
	}


	pointsQueue->toString();

	delete pointsQueue;

	return 0;
}