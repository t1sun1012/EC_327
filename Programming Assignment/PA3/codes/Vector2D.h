#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>
#include <cmath>

using namespace std;



class Vector2D {
    public:
    double x;
    double y;

    // default constructor
    Vector2D();


    // other constructor
    Vector2D(double in_x, double in_y);



};


// overloading operators

// multiplication operator, vector multiplies by a value, return vector
Vector2D operator * (Vector2D v1, double d);

// division operator, vector divided by a value, return vector
Vector2D operator / (Vector2D v1, double d);

// stream output operator, formatting output
ostream& operator << (ostream& out, Vector2D v1);





#endif