#include <iostream>

#include "GameObject.h"

using namespace std;


// constructors

GameObject::GameObject(char in_code)
{
    display_code = in_code;
    id_num = 1;
    state = 0;
    cout << "GameObject constructed" << endl;
}

GameObject::GameObject(Point2D in_loc, int in_id, char in_code)
{
    location = in_loc;
    id_num = in_id;
    display_code = in_code;
    state = 0;
    cout << "GameObject constructed" << endl;
}

GameObject::~GameObject()
{
    // virtual so deleting through GameObject* can go to the specific derived object destructor
    cout << "GameObject destructed." << endl;
}

Point2D GameObject::GetLocation()
{
    return location;
}

int GameObject::GetId()
{
    return id_num;
}

char GameObject::GetState()
{
    return state;
}

void GameObject::DrawSelf(char* ptr)
{
    ptr[0] = display_code;
    ptr[1] = static_cast<char>('0' + id_num);
}

void GameObject::ShowStatus()
{
    cout << "(" << display_code << ")(" << id_num << ") at " << location;
}

void GameObject::save(ofstream& file)
{
    // Save base fields first so derived restore functions can read in the same order.
    file << location.x << ' ' << location.y << ' ' << id_num << ' '
         << display_code << ' ' << static_cast<int>(state) << endl;
}

void GameObject::restore(ifstream& file, Model& model)
{
    int state_value;

    file >> location.x >> location.y >> id_num >> display_code >> state_value;
    state = static_cast<char>(state_value);
}
