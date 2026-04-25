#include <iostream>
#include <cmath>

#include "Vector2D.h"

using namespace std;

Vector2D::Vector2D()
{
    x = 0.0;
    y = 0.0;
}

Vector2D::Vector2D(double in_x, double in_y)
{
    x = in_x;
    y = in_y;
}


// overloading operators

// multiplication operator, vector multiplies by a value, return vector
Vector2D operator * (Vector2D v1, double d){
    Vector2D result;
    result.x = v1.x * d;
    result.y = v1.y * d;
    return result;
}

// division operator, vector divided by a value, return vector
Vector2D operator / (Vector2D v1, double d) {
    if (d == 0) {
        return v1;
    }
    return Vector2D(v1.x / d, v1.y / d);
}

// stream output operator, formatting output
ostream& operator << (ostream& out, const Vector2D& v1) {
    out << '<' << v1.x << ", " << v1.y << '>';
    return out;
}

