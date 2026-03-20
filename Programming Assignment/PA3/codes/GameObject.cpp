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
    GameObject(char in_code) {
        display_code = in_code;
        id_num = 1;
        state = 0;
        cout << "GameObject constructed";
    }

    GameObject(Point2D in_loc, int in_id, char in_code) {
        display_code = in_code;
        id_num = in_id;
        location = in_loc;
        state = 0;
        cout << "GameObject constructed";
    }

    Point2D GetLocation() {
        return location;
    }

    int GetId() {
        return id_num;
    }

    char GetState() {
        return state;
    }

    void ShowStatus() {
        cout << "(" << display_code << ")(" << id_num << ") at " << location; 
    }


};
