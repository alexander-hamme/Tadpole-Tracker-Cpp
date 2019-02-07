#include <iostream>

#include "CircularPointsQueue.cpp"


int main() {

	std::cout << "Hello, World!" << std::endl;

	// auto assumes type  (since c++11)
	auto *pointsQueue = new CircularPointsQueue(5);

	// todo: have to change the values that the pointer points too,
	// not try to create new objects!

	Point pt1;
	pt1.x = 2;
	pt1.y = 6;

	Point pt2;
	pt2.x = 5;
	pt2.y = 7;

	Point pt3;
	pt3.x = 1;
	pt3.y = 0;


	/*Point *pt2 = new Point(2,6);
	Point *pt3 = new Point(5,1);
	Point *pt4 = new Point(6,2);*/

	pointsQueue->add(pt1);
	pointsQueue->add(pt2);
	pointsQueue->add(pt3);


	pointsQueue->toString();

	delete pointsQueue;

	return 0;
}