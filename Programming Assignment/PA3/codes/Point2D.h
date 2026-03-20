#ifndef POINT2D_H
#define POINT2D_H


#include <iostream>
#include <cmath>

#include "Vector2D.h"

using namespace std;


class Point2D {
    public:
    double x; // the x value of the point
    double y; // the y value fo the point


    // default constructor
    Point2D();

    // other constructor
    // set x and y to in_x and in_y, respectively
    Point2D(double in_x, double in_y);
    
};


// cartesian distance
double GetDistanceBetween(Point2D p1, Point2D p2);



// Overloaded Operators

// stream output operator formatting
ostream& operator << ( ostream& out, Point2D& p1);

// addition operator, adding point to a vector, return point
Point2D operator + (Point2D p1, Vector2D v1);

// subtraction operator, subtracting point with a point, return vector
Vector2D operator - (Point2D p1, Point2D p2);





#endif