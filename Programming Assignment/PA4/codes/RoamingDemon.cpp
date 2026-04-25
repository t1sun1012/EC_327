#include <iostream>

#include "RoamingDemon.h"
#include "Mage.h"

using namespace std;

RoamingDemon::RoamingDemon(string in_name, double in_attack, double in_health, bool in_variant,
    int in_id, Point2D in_loc)
    : GameObject(in_loc, in_id, 'W')
{
    // choose the exact demon behavior, so the constructor accepts
    // the main values needed for both default demons and future new commands.
    name = in_name;
    attack = in_attack;
    health = in_health;
    variant = in_variant;
    in_combat = false;
    current_mage = NULL;
    state = IN_ENVIRONMENT;
    cout << "RoamingDemon constructed" << endl;
}

RoamingDemon::~RoamingDemon()
{
    cout << "RoamingDemon destructed." << endl;
}

void RoamingDemon::follow(Mage* m)
{
    // Only living demons can attach to a valid Mage target.
    if (m == NULL || !IsAlive()) {
        return;
    }

    // Store the target here and notify the Mage so it can apply the mana penalty.
    current_mage = m;
    in_combat = true;
    state = IN_HUNT;
    m->StartBeingFollowed(this);
    cout << "RoamingDemon " << id_num << " is following " << m->GetName() << endl;
}

bool RoamingDemon::get_variant()
{
    return variant;
}

double RoamingDemon::get_attack()
{
    return attack;
}

double RoamingDemon::get_health()
{
    return health;
}

bool RoamingDemon::get_in_combat()
{
    return in_combat;
}

bool RoamingDemon::IsAlive()
{
    return health > 0;
}

bool RoamingDemon::Update()
{
    // Dead demons are no longer visible or in combat.
    if (!IsAlive() && state != DEAD) {
        state = DEAD;
        display_code = 'w';
        in_combat = false;
        current_mage = NULL;
        cout << "RoamingDemon " << id_num << " has died." << endl;
        return true;
    }

    if (state == IN_HUNT && current_mage != NULL) {
        // A hunting demon stays on top of the Mage it follows.
        location = current_mage->GetLocation();
    }

    return false;
}

bool RoamingDemon::ShouldBeVisible()
{
    return IsAlive();
}

void RoamingDemon::ShowStatus()
{
    cout << "RoamingDemon Status: ";
    GameObject::ShowStatus();

    // Print state-specific details in the same style as other GameObject classes.
    if (!IsAlive()) {
        cout << " dead" << endl;
    }
    else if (state == IN_HUNT && current_mage != NULL) {
        cout << " hunting Mage " << current_mage->GetId() << endl;
    }
    else {
        cout << " roaming in the environment" << endl;
    }

    cout << "Attack: " << attack << endl;
    cout << "Health: " << health << endl;
    cout << "Variant: " << variant << endl;
}
