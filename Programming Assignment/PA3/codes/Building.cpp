#include <iostream>

#include "Building.h"

using namespace std;


// Base class for all buildin type objects, inherits from GameObject
class Building: public GameObject {
    private:
    unsigned int mage_count = 0;

    Building() {
        display_code = 'B';
        cout << "Building default constructed";
    }

    Building(char in_code, int in_Id, Point2D in_loc) {
        id_num = in_Id;
        location = in_loc;
        display_code = in_code;
        cout << "Building constructed";
    }

    public:
    void AddOneMage();

    void RemoveOneMage();

    void ShowStatus();

    bool ShouldBeVisible();

};