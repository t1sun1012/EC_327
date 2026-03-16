/**************************************************************
 * The interface file for the Poly class                      *
 **************************************************************/

#ifndef  POLY_H
#define POLY_H
#include <iostream>
#include <string>
#include <cassert>
#include <iomanip>
using namespace std;


// Definition for the Poly class
class Poly
{
  private:
    int degree;
    double* ptr;
  public:
    Poly ();
    Poly (int degree);
    Poly (int degree, double coef);  // One-term polynomial 
    ~Poly ();
    Poly (const Poly& origin);
    Poly& operator= (const Poly& right ); 
    void fill ();
    int max (int x, int y);
    friend const Poly operator+ (const Poly& left, 
                                 const Poly& right);
    friend const Poly operator- (const Poly& left, 
                                 const Poly& right);

    friend const Poly operator* (const Poly& left, 
                                 const Poly& right);

    friend const Poly operator/ (const Poly& left, 
                                 const Poly& right);
    friend const Poly operator% (const Poly& left, 
                                 const Poly& right);
    friend ostream& operator << (ostream& left, 
                                 const Poly& poly);	 
};

#endif

