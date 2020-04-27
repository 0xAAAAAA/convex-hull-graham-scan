#include "graham_scan.h"

std::ostream & operator << (std::ostream & os, const Point & p) {os << "Point {"<< p.x << ", " << p.y << "}" << std::endl; return os;}

std::vector<Point> GrahamScan::compute(std::vector<Point> & points) {
	int n = points.size();
	
	// Find p0 ie. the point with the minimum coordinate. min is the index of the p0 point
	int ymin = points[0].y, min = 0;

	for (int i = 0; i < n; ++i) {
		// the Y coordinate or current point
		int y = points[i].y;

		// if Y is less than ymin or if they are equal then select the point with a smaller X value
		if ((y < ymin) || (y == ymin && points[i].x < points[min].x)) {
			ymin = y;
			min = i;
		}
	}

	// swap the positions of thw lowest Y point with points[0]
	std::swap(points[0], points[min]);

	// Make p0 for sorting function
	Point p0 = points[0];

	// sort remaining points in order of their polar angles from p0
	std::sort(points.begin(), points.end(), [&p0] (const struct Point & lhs, const struct Point & rhs) {
		// check if the points are not equal
		assert(!(lhs.x == rhs.x && lhs.y == rhs.y));

		// the polar angles of both the points wrt Point p0 converted to degrees
		float l_angle = (atan2(lhs.y - p0.y, lhs.x - p0.x)) * 180 / M_PI;
		float r_angle = (atan2(rhs.y - p0.y, rhs.x - p0.x)) * 180 / M_PI;

		return l_angle < r_angle;
	});

	// Init stack (using vector to get index access)
	std::vector<Point> s;

	// push first 3 points on stack
	s.push_back(points[0]); // p0
	s.push_back(points[1]); // p1
	s.push_back(points[2]); // p2

	for (int i = 3; i < n; ++i) {
		// if the orientation is collinear or clockwise pop the stack and add the current point on top of stack
		while (orientation(s[s.size()-2], s[s.size()-1], points[i]) != 2) s.pop_back();
		s.push_back(points[i]);
	}

	return s;
}

int GrahamScan::orientation(Point & p, Point & q, Point & r) { 
	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); 
  
	if (val == 0) return 0;  // colinear 
	return (val > 0) ? 1: 2; // clock or counterclock wise 
} 