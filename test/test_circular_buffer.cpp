//
// Created by alex on 2/7/19.
//

#include <iostream>
#include "test_circular_buffer.h"

#include "gtest/gtest.h"

using namespace std;


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


/**
 * Simple test where buffer has not reached capacity
 */
TEST(TEST_Q_ELEMENTS, UnderCapacityCheck) {

	unsigned numbpts = 10;

	auto *points_buffer = new CircularBuffer(numbpts + 5);

	vector<Point> truth_points(numbpts);

	for (int i = 0; i < numbpts; i++) {
		Point pt = {i, i};
		points_buffer->add(pt);
		truth_points.at(numbpts - i - 1) = pt;
	}

	EXPECT_TRUE(testBufferElements(points_buffer, truth_points));

	delete points_buffer;
}



/**
 * Test where buffer is at capacity
 * (tests circular traversal of buffer)
 */
TEST(TEST_Q_ELEMENTS, AtCapacityCheck) {

	unsigned numbpts = 10;

	auto *points_buffer = new CircularBuffer(numbpts);

	vector<Point> truth_points(numbpts);

	for (int i = 0; i < numbpts; i++) {
		Point pt = {i, i};
		points_buffer->add(pt);
		truth_points.at(numbpts - i - 1) = pt;
	}

	EXPECT_TRUE(testBufferElements(points_buffer, truth_points));

	delete points_buffer;
}


/**
 * Test where points are added to buffer after it has reached capacity
 *
 * (this is to check that FIFO traversal gives the correct order)
 */
TEST(TEST_Q_ELEMENTS, OverCapacityCheck) {

	unsigned numbpts = 10;

	auto *points_buffer = new CircularBuffer(numbpts);

	vector<Point> truth_points(numbpts);

	for (int i = 0; i < numbpts * 2; i++) {
		Point pt = {i, i};
		points_buffer->add(pt);
	}

	size_t j = 0;
	for (int i=numbpts * 2 - 1; i>=numbpts; i--) {
		Point pt = {i, i};
		truth_points.at(j++) = pt;
	}

	EXPECT_TRUE(testBufferElements(points_buffer, truth_points));

	delete points_buffer;
}

/**
 * Checks if all Point structs in the buffer are equal
 * (have the same x and y values) to those in truthPoints vector
 *
 * @param c_buffer pointer to a CircularBuffer object
 * @param truth_points vector containing Point structs
 * @return bool
 */
bool testBufferElements(CircularBuffer *c_buffer, vector<Point> truth_points) {

	if (c_buffer->getSize() != truth_points.size()) {

		cout << "CircularBuffer and truth_points are not of equal size:" << endl;

		c_buffer->printPoints();

		cout << endl;

		for (Point pt : truth_points) {
			printf("(%d, %d)", pt.x, pt.y);
		}

		cout << endl;

		return false;
	}

	auto q_idx = static_cast<unsigned int>(c_buffer->getFront());
	int q_rear = c_buffer->getRear();

	int capacity = c_buffer->getSize();
	bool atCapacity = c_buffer->isAtCapacity();

	vector<Point> elements = c_buffer->getElements();

	unsigned int t_indx = 0;   // truth_points index


	bool allEqual = true;

	if (!atCapacity) {

		// if c_buffer is not at capacity, FIFO traversal is simple,
		// because elements are inserted in reverse order into the array.
		// Accessing elements in FIFO order is done by incrementing `front` to `rear`

		while (q_idx <= q_rear) {

			if (elements.at(q_idx).x != truth_points.at(t_indx).x
			    || elements.at(q_idx).y != truth_points.at(t_indx).y) {

				allEqual = false;
				break;
			}

			q_idx++;
			t_indx++;
		}

	} else {

		// if c_buffer is at capacity, `front` is incremented circularly around
		// the array until it reaches `rear`.
		while (q_idx != q_rear) {

			if (elements.at(q_idx).x != truth_points.at(t_indx).x
			    || elements.at(q_idx).y != truth_points.at(t_indx).y) {

				allEqual = false;
				break;
			}

			q_idx = (q_idx + 1) % capacity;
			t_indx++;

			// one extra check must be included for when front reaches
			// (is equal to) rear, because rear is always at the last element
			// (in FIFO order) in the array
			if (q_idx == q_rear) {

				if (elements.at(q_idx).x != truth_points.at(t_indx).x
				    || elements.at(q_idx).y != truth_points.at(t_indx).y) {

					allEqual = false;
				}
				break;
			}
		}
	}

	if (! allEqual) {

		cout << "CircularBuffer and truth_points are not equal:" << endl;

		c_buffer->printPoints();

		cout << endl;


		for (Point pt : truth_points) {
			printf("(%d, %d) ", pt.x, pt.y);
		}

		cout << endl;

		return false;
	}
	return true;
}