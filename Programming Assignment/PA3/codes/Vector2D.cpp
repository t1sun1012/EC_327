#include <iostream>
#include <cmath>

using namespace std;


class Vector2D {
    public:
    double x;
    double y;

    // default constructor
    Vector2D() {
        x = 0.0;
        y = 0.0;
    }


    // other constructor
    Vector2D(double in_x, double in_y) {
        x = in_x;
        y = in_y;
    }


};


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
    return Vector2D(v1.x/d, v1.y/d);
}

// stream output operator, formatting output
ostream& operator << (ostream& out, Vector2D v1) {
    out << '<' << v1.x << ',' << v1.y << '>';
    return out;
}

