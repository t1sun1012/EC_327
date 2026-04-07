#include <iostream>

#include "Building.h"

using namespace std;

// default constructor
Building::Building() : GameObject('B')
{
    mage_count = 0;
    cout << "Building default constructed" << endl;
}

// other constructor
Building::Building(char in_code, int in_id, Point2D in_loc) : GameObject(in_loc, in_id, in_code)
{
    mage_count = 0;
    cout << "Building constructed" << endl;
}

// add one mage
void Building::AddOneMage()
{
    mage_count++;
}

// remove one mage
void Building::RemoveOneMage()
{
    if (mage_count > 0) {
        mage_count--;
    }
}

// show status
void Building::ShowStatus()
{
    cout << "(" << display_code << ")(" << id_num << ") located at " << location << endl;

    cout << mage_count << " ";
    if (mage_count == 1) {
        cout << "mage is";
    }
    else {
        cout << "mages are";
    }
    cout << " in this building" << endl;
}

// should be visible
bool Building::ShouldBeVisible()
{
    return true;
}
