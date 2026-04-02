#ifndef BUILDING_H

#define BUILDING_H

#include "GameObject.h"

// Base class for all buildin type objects, inherits from GameObject
class Building: public GameObject {
    private:
    unsigned int mage_count;

    Building();

    Building(char in_code, int in_Id, Point2D in_loc);

    public:
    void AddOneMage();

    void RemoveOneMage();

    void ShowStatus();

    bool ShouldBeVisible();

};



#endif

