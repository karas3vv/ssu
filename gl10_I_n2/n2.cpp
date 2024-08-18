#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

struct point {
	int x, y;
};

double distance(point& p) {
	return sqrt(pow(p.x, 2) + pow(p.y, 2));
}

int main() {
	setlocale(LC_ALL, "Russian");

	point points[100];
	int numPoints = 0;

	ifstream in("input.txt");
	point p;

	while (in >> p.x >> p.y) {
		points[numPoints] = p;
		++numPoints;
	}

	double maxDistance = -1;
	point farthestPoint;

	for (int i = 0; i < numPoints; ++i) {
		double dist = distance(points[i]);
		if (dist > maxDistance) {
			maxDistance = dist;
			farthestPoint = points[i];
		}
	}

	cout << "Ќаиболее удаленна€ точка от начала координат: (" << farthestPoint.x << ", " << farthestPoint.y << ")" << endl;
	return 0;
}