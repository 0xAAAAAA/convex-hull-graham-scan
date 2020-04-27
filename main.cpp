#include <iostream>
#include "graham_scan.h"

#define space " "

using namespace std;

int main() {
	// get data
	int n; cin >> n;
	
	int x, y;
	vector<Point> points;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		points.push_back(Point {x, y});
	}

	GrahamScan gs;
	vector<Point> convex_points = gs.compute(points);

	cout << convex_points.size();
	for (auto point: convex_points) {
		cout << endl << point.x << space << point.y;
	}
}
