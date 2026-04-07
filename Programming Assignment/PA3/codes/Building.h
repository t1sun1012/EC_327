#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>

#include "GameObject.h"

using namespace std;


// inheritance from public GameObject
class Building : public GameObject {
    private:
    unsigned int mage_count;

    public:
    Building();
    Building(char in_code, int in_id, Point2D in_loc);

    void AddOneMage();
    void RemoveOneMage();
    void ShowStatus();
    bool ShouldBeVisible();
};

#endif
