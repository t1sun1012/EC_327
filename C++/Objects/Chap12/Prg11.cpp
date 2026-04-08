/**************************************************************
 * The interface file for the Square class                    *
 **************************************************************/

#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"

// Class Definition
class Square : public Shape
{	
  private:
    double side;
    bool isValid() const;
  public:
    Square (double side);
    ~Square ();
    void print() const;
    double getArea () const;
    double getPerimeter () const;
};

#endif



