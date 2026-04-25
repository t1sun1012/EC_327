#ifndef ROAMINGDEMON_H
#define ROAMINGDEMON_H

#include <iostream>
#include <string>

#include "GameObject.h"

using namespace std;

class Mage;

// RoamingDemon uses a small state machine like Mage, but only needs to know
// whether it is idle, dead, or currently hunting a Mage.
enum RoamingDemonStates {
    IN_ENVIRONMENT = 0,
    DEAD = 1,
    IN_HUNT = 2
};

class RoamingDemon : public GameObject {
    protected:
    // These instance fields describe the demon and its current target.
    double attack;
    double health;
    bool variant;
    bool in_combat;
    string name;
    Mage* current_mage;

    public:
    RoamingDemon(string in_name, double in_attack, double in_health, bool in_variant,
        int in_id, Point2D in_loc);
    ~RoamingDemon() override;

    // Begin following a Mage after Model detects same location contact.
    void follow(Mage* m);
    bool get_variant();
    double get_attack();
    double get_health();
    bool get_in_combat();
    bool IsAlive();
    bool Update() override;
    bool ShouldBeVisible() override;
    void ShowStatus() override;
};

#endif
