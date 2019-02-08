#include <iostream>

#include "CircularPointsQueue.h"


void readElements(CircularPointsQueue *queue) {

	auto idx = static_cast<unsigned int>(queue->getFront());
	int rear = queue->getRear();

	bool atCapacity = queue->isAtCapacity();

	vector<Point> elements = queue->getElements();

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
}

int main() {

	std::cout << "Hello, World!" << std::endl;

	// auto assumes type  (since c++11)
	auto *pointsQueue = new CircularPointsQueue(10);

	// todo: have to change the values that the pointer points too,
	// not try to create new objects!


	for (int i=-5; i<10; i++) {
		Point pt = {i, i};
		pointsQueue->add(pt);
	}

	pointsQueue->toString();

	delete pointsQueue;

	return 0;
}