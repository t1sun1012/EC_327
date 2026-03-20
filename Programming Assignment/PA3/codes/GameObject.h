#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>

#include "Point2D.h"

using namespace std;

class GameObject {
    private:
    Point2D location; // object location
    int id_num; // object ID
    char display_code; // how the object is represented in the View
    char state; // state of the object

    public:
    // constructors
    GameObject(char in_code);

    GameObject(Point2D in_loc, int in_id, char in_code);

    Point2D GetLocation();

    int GetId();

    char GetState();

    void ShowStatus();


};


#endif