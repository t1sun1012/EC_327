#include <iostream>
#include <cmath>

#include "Point2D.h"

using namespace std;


// default constructor
Point2D::Point2D()
{
    x = 0.0;
    y = 0.0;
}

Point2D::Point2D(double in_x, double in_y)
{
    x = in_x;
    y = in_y;
}


double GetDistanceBetween(Point2D p1, Point2D p2) {
    // cartesian distance formula
    return sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
}



// Overloaded Operators

// stream output operator formatting
ostream& operator << (ostream& out, const Point2D& p1) {
    out << '(' << p1.x << ", " << p1.y << ')';
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






