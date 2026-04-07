#include <iostream>

#include "GameObject.h"
#include "Point2D.h"
#include "Vector2D.h"

using namespace std;

int main()
{
    Point2D p1;
    Point2D p2(3.14, 7.07);
    Point2D p3(3, 7);
    Point2D p4(5, -2);

    Vector2D v1;
    Vector2D v2(5, -2);
    Vector2D v3(10, 20);

    cout << "Point tests:" << endl;
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "Distance between p3 and p4 = " << GetDistanceBetween(p3, p4) << endl;
    cout << "p3 + v2 = " << (p3 + v2) << endl;
    cout << "p3 - p4 = " << (p3 - p4) << endl;

    cout << endl;
    cout << "Vector tests:" << endl;
    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;
    cout << "v3 * 5 = " << (v3 * 5) << endl;
    cout << "v3 / 5 = " << (v3 / 5) << endl;
    cout << "v3 / 0 = " << (v3 / 0) << endl;

    cout << endl;
    cout << "GameObject tests:" << endl;
    GameObject g1('g');
    cout << endl;
    GameObject g2(Point2D(2.5, 4.5), 7, 'x');
    cout << endl;
    g1.ShowStatus();
    cout << endl;
    g2.ShowStatus();
    cout << endl;

    return 0;
}
