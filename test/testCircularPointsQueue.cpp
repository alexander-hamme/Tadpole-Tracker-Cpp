//
// Created by alex on 2/7/19.
//

#include <iostream>
#include "testCircularPointsQueue.h"

#include "gtest/gtest.h"

using namespace std;


bool testQueueElements(CircularPointsQueue *queue, vector<Point> truthPoints) {

	if (queue->getSize() != truthPoints.size()) {
		return false;
	}

	auto idx = static_cast<unsigned int>(queue->getFront());
	int rear = queue->getRear();

	int capacity = queue->getSize();
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


	// todo

	for (Point pt : truthPoints) {

	}

	// todo check all elements are equal
	return true;
}


bool simpleTest() {

	auto *pointsQueue = new CircularPointsQueue(10);

	vector<Point> truthPoints(10);

	for (int i=0; i<10; i++) {
		Point pt = {i, i};
		pointsQueue->add(pt);
		truthPoints.push_back(pt);
	}

	bool passed = testQueueElements(pointsQueue, truthPoints);

	delete pointsQueue;

	return passed;

}

void runAllTests() {

	simpleTest();

}