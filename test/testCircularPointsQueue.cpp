//
// Created by alex on 2/7/19.
//

#include <iostream>
#include "testCircularPointsQueue.hpp"

#include "gtest/gtest.h"

using namespace std;

/**
 * Simple test where queue has not reached capacity
 */
TEST(testQueueElements, UnderCapacityCheck) {

	unsigned numbpts = 10;

	auto *pointsQueue = new CircularPointsQueue(numbpts + 5);

	vector<Point> truthPoints(numbpts);

	for (int i = 0; i < numbpts; i++) {
		Point pt = {i, i};
		pointsQueue->add(pt);
		truthPoints.push_back(pt);
	}

	EXPECT_TRUE(testQueueElements(pointsQueue, truthPoints));

	delete pointsQueue;
}



/**
 * Test where queue is at capacity
 * (tests circular traversal of queue)
 */
TEST(testQueueElements, AtCapacityCheck) {

	unsigned numbpts = 10;

	auto *pointsQueue = new CircularPointsQueue(numbpts);

	vector<Point> truthPoints(numbpts);

	for (int i = 0; i < numbpts; i++) {
		Point pt = {i, i};
		pointsQueue->add(pt);
		truthPoints.push_back(pt);
	}

	EXPECT_TRUE(testQueueElements(pointsQueue, truthPoints));

	delete pointsQueue;
}


/**
 * Test where points are added to queue after it has reached capacity
 *
 * (this is to check that FIFO traversal gives the correct order)
 */
TEST(testQueueElements, OverCapacityCheck) {

	unsigned numbpts = 10;

	auto *pointsQueue = new CircularPointsQueue(numbpts);

	vector<Point> truthPoints(numbpts);

	for (int i = 0; i < numbpts * 2; i++) {
		Point pt = {i, i};
		pointsQueue->add(pt);
	}

	for (int i=numbpts * 2 - 1; i>=numbpts; i--) {
		Point pt = {i, i};
		truthPoints.push_back(pt);
	}

	EXPECT_TRUE(testQueueElements(pointsQueue, truthPoints));

	delete pointsQueue;
}

/**
 * Checks if all Point structs in the queue are equal
 * (have the same x and y values) to those in truthPoints vector
 *
 * @param queue pointer to a CircularPointsQueue object
 * @param truthPoints vector containing Point structs
 * @return bool
 */
bool testQueueElements(CircularPointsQueue *queue, vector<Point> truthPoints) {

	if (queue->getSize() != truthPoints.size()) {

		cout << "Queue and truthPoints are not of equal size:" << endl;

		queue->printPoints();

		for (Point pt : truthPoints) {
			printf("(%d, %d)", pt.x, pt.y);
		}

		return false;
	}

	auto q_idx = static_cast<unsigned int>(queue->getFront());
	int q_rear = queue->getRear();

	int capacity = queue->getSize();
	bool atCapacity = queue->isAtCapacity();

	vector<Point> elements = queue->getElements();

	unsigned int t_indx = 0;   // truthPoints index


	bool allEqual = true;

	if (!atCapacity) {

		// if queue is not at capacity, FIFO traversal is simple,
		// because elements are inserted in reverse order into the array.
		// Accessing elements in FIFO order is done by incrementing `front` to `rear`

		while (q_idx <= q_rear) {

			if (elements.at(q_idx).x != truthPoints.at(t_indx).x
			    || elements.at(q_idx).y != truthPoints.at(t_indx).y) {

				allEqual = false;
				break;
			}

			q_idx++;
			t_indx++;
		}

	} else {

		// if queue is at capacity, `front` is incremented circularly around
		// the array until it reaches `rear`.
		while (q_idx != q_rear) {

			if (elements.at(q_idx).x != truthPoints.at(t_indx).x
			    || elements.at(q_idx).y != truthPoints.at(t_indx).y) {

				allEqual = false;
				break;
			}

			q_idx = (q_idx + 1) % capacity;
			t_indx++;

			// one extra check must be included for when front reaches
			// (is equal to) rear, because rear is always at the last element
			// (in FIFO order) in the array
			if (q_idx == q_rear) {

				if (elements.at(q_idx).x != truthPoints.at(t_indx).x
				    || elements.at(q_idx).y != truthPoints.at(t_indx).y) {

					allEqual = false;
				}
				break;
			}
		}
	}

	if (! allEqual) {

		cout << "Queue and truthPoints are not equal:" << endl;

		queue->printPoints();

		for (Point pt : truthPoints) {
			printf("(%d, %d) ", pt.x, pt.y);
		}
		return false;
	}
	return true;
}



int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}