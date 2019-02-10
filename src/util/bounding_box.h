//
// Created by alex on 2/9/19.
//

#ifndef SPROJ_CPP_BOUNDING_BOX_HPP
#define SPROJ_CPP_BOUNDING_BOX_HPP

#endif

#include <cmath>
#include <string>

using namespace std;

class BoundingBox {

public:

	const int top_left_x;
	const int top_left_y;
	const int bot_right_x;
	const int bot_right_y;

	const int center_x;
	const int center_y;

	explicit BoundingBox(int x1, int y1, int x2, int y2)
	: top_left_x(x1), top_left_y(y1), bot_right_x(x2), bot_right_y(y2),
		center_x(x1 + (int) ((x2 - x1) / 2.0)),
		center_y(y1 + (int) ((y2 - y1) / 2.0))
		{};

	explicit BoundingBox(int center_pos[2], int width, int height)
	: center_x(center_pos[0]), center_y(center_pos[1]),
		top_left_x(center_pos[0] - (int) round(width / 2.0)),
		top_left_y(center_pos[1] - (int) round(height / 2.0)),
		bot_right_x(center_pos[0] + (int) round(width / 2.0)),
		bot_right_y(center_pos[1] + (int) round(height / 2.0))
		{};

	// these functions are just defined here in this header file because they are simple,
	// and as member functions inside a class, they are implicitly inline and therefore
	// will not break the one-definition-rule.
	bool contains(const int pt[2]) {
		return pt[0] >= this->top_left_x && pt[0] <= this->bot_right_x
		    && pt[1] >= this->top_left_y && pt[1] <= this->bot_right_y;
	}

	string string_summary() {
		return "(" + std::to_string(top_left_x) + "," + std::to_string(top_left_y)
			+ "), (" + std::to_string(bot_right_x) + "," + std::to_string(bot_right_y) + ")";
	}

};



