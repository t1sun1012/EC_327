#include <iostream>
#include <cmath>

#include "Vector2D.h"

using namespace std;

class Point2D {
    public:
    double x; // the x value of the point
    double y; // the y value fo the point

    // default constructor
    Point2D() {
        x = 0.0;
        y = 0.0;
    }


    // other constructor
    Point2D(double in_x, double in_y) {
        // set x and y to in_x and in_y, respectively
        x = in_x;
        y = in_y;

    }


};


double GetDistanceBetween(Point2D p1, Point2D p2) {
    // cartesian distance formula
    return sqrt(pow((p2.x-p1.x),2) + pow((p2.y - p1.y),2));
}



// Overloaded Operators

// stream output operator formatting
ostream& operator << ( ostream& out, Point2D& p1) {
    out << '(' << p1.x << ',' << p1.y << ')';
    return out;
}

// addition operator, adding point to a vector, return point
Point2D operator + (Point2D p1, Vector2D v1){
    return Point2D(p1.x + v1.x, p1.y + v1.y);
}

// subtraction operator, subtracting point with a point, return vector
Vector2D operator - (Point2D p1, Point2D p2){
    return Vector2D(p1.x - p2.x, p1.y - p2.y);
}





