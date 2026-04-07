#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>

#include "Point2D.h"

using namespace std;

class GameObject {
    protected:
    Point2D location; // object location
    int id_num; // object ID
    char display_code; // how the object is represented in the View
    char state; // state of the object

    public:
    // constructors
    GameObject(char in_code);

    GameObject(Point2D in_loc, int in_id, char in_code);

    virtual ~GameObject();

    Point2D GetLocation();

    int GetId();

    char GetState();

    // Derived classes supply object-specific behavior through this interface.
    virtual void ShowStatus();
    virtual bool Update() = 0;
    virtual bool ShouldBeVisible() = 0;

};


#endif