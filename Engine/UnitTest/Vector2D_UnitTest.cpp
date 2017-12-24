#include "Source/Math/Vector2D.h"
#include <assert.h>
#include "iostream"

using namespace std;
bool Vector2D_UnitTest() {
	const Vector2D vector(2, 2);
	double x, y;
	x = vector.get_x();
	y = vector.get_y();

	cout << "x: " << x << ", " << "y: " << y << endl;

	Vector2D v(1, 1);
	v = v + vector;
	cout<< v<< endl;
	
	Vector2D v2(1, 1);
	v2 = vector + v2;
	cout << v2 << endl;
	
	Vector2D v3(1, 1);
	v3 = vector - v3;
	cout << v3 << endl;

	Vector2D v4(1, 1);
	v4 = v4 - vector;
	cout << v4 << endl;

	cout << "End of Unit Test" << endl;
	return true;
}