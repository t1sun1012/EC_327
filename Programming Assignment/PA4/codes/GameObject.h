#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <fstream>
#include <iostream>

#include "Point2D.h"

using namespace std;

class Model;

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

    // View uses this to ask every object for its two-character grid marker.
    void DrawSelf(char* ptr);

    // virtual functions for derived classes to implement.
    virtual void ShowStatus();
    virtual void save(ofstream& file);
    virtual void restore(ifstream& file, Model& model);
    virtual bool Update() = 0;
    virtual bool ShouldBeVisible() = 0;

};


#endif