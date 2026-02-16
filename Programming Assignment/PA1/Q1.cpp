#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Enter three x,y coordinates:" << endl;
    
    // initialize points variables 
    float x1; float y1; float x2; float y2; float x3; float y3;
    // get the input values to coordinates variables
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;


    // compute the parameters for line equation ax + by + c = 0
    float a = y1 - y2;
    float b = x2 - x1;
    float c = x1*y2 - x2*y1;

    // compute shortest distance
    float d = abs(a*x3 + b*y3 + c) / sqrt(pow(a,2) + pow(b,2));

    cout << "The shortest distance for (" << x3 << "," << y3 << ") to the line composed of (" << x1 << "," << y1 << ") and (" << x2 << "," << y2 << ") is " << d << "." << endl;
}


