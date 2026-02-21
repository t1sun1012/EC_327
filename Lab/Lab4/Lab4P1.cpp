#include <iostream>

#include "xFactor.h"

using namespace std;

int main() {
    char again = 'y';


    while (again = 'y') {
    
        
    cout << "What are the coefficients of your quadratic?" << endl;
    int a, b, c;
    cin >> a >> b >> c;

    cout << "What is the tolerance you would like?" << endl;
    double tol;
    cin >> tol;

    double pos_x = positiveX(a,b,c,tol);
    double neg_x = negativeX(a,b,c,tol);
    cout << "x = (" << pos_x << "," << neg_x << ")" << endl;
    
    cout << "Again? (y/n)" << endl;
    cin >> again;
    if (again == 'n') {
        break;
    }
    }
}
