#ifndef GRAHAM_SCAN_H
#define GRAHAM_SCAN_H

#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <iostream>

struct Point {
	int x, y;
};

std::ostream & operator <<(std::ostream & os, const Point & p);

class GrahamScan {
public:
	std::vector<Point> compute(std::vector<Point> & points);
private:
	int orientation(Point & p, Point & q, Point & r);
};


#endif