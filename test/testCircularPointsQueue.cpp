//
// Created by alex on 2/7/19.
//

#include <iostream>
#include "testCircularPointsQueue.h"

#include "gtest/gtest.h"

using namespace std;


TEST(testQueueElements, SimpleTestElements) {

	auto *pointsQueue = new CircularPointsQueue(10);

	vector<Point> truthPoints(10);

	for (int i = 0; i < 10; i++) {
		Point pt = {i, i};
		pointsQueue->add(pt);
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

/**
 * Simple test with queue under capacity
 * @return
 */
bool simpleTest() {

	int numbpts = 10;

	auto *pointsQueue = new CircularPointsQueue(numbpts + 5);

	vector<Point> truthPoints(numbpts);

	for (int i = 0; i < numbpts; i++) {
		Point pt = {i, i};
		pointsQueue->add(pt);
		truthPoints.push_back(pt);
	}

	bool passed = testQueueElements(pointsQueue, truthPoints);

	delete pointsQueue;

	return passed;

}

//void runAllTests() {
//
//	simpleTest();
//
//}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}