/*
7.5 Given two squares on a two-dimensional plane, find a line that would cut these
   two squares in half. Assume that the top and the bottom sides of the square run
  parallel to the x-axis.
*/

#include <iostream>

class Solution {
public:
	Line find_line(Point p1, double l1, Point p2, double l2) {
		Point center1, center2;
		Line ret;

		center1.x = p1.x + l1/2;
		center1.y = p1.y - l1/2;

		center2.x = p2.x + l2/2;
		center2.y = p2.y - l2/2;

		if (center1.y == center2.y) {
			Line.rate = 0;
			Line.c = center1.y;
			return Line;			
		}	

		if (center1.x == center2.x) {
			Line.rate = MAX;
			Line.c = center1.x;
			return Line;
		}	

		Line.rate = (center2.y - center1.y)/(center2.x - center1.x);
		Line.c = cneter2.y - Line.rate * center2.x;

		return Line;
	}
};
