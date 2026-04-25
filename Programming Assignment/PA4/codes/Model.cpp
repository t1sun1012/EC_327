#include <iostream>
#include <cstdlib>

#include "Input_Handling.h"
#include "Model.h"
#include "View.h"

using namespace std;

Model::Model()
{
    time = 0;

    // Build the default world in front-to-back order 
    Mage* mage1 = new Mage("Serena", 1, 'M', 1, Point2D(5, 1));
    Mage* mage2 = new Mage("Rumi", 2, 'M', 2, Point2D(10, 1));
    ManaSpire* spire1 = new ManaSpire(1, 1, 100, Point2D(1, 20));
    ManaSpire* spire2 = new ManaSpire(2, 2, 200, Point2D(10, 20));
    DemonHideout* hideout1 = new DemonHideout(10, 1, 2, 3, 1, Point2D(0, 0));
    DemonHideout* hideout2 = new DemonHideout(20, 5, 7.5, 4, 2, Point2D(5, 5));
    // adds two default RoamingDemons to the world.
    RoamingDemon* demon1 = new RoamingDemon("Ash", 5, 2, false, 1, Point2D(10, 12));
    RoamingDemon* demon2 = new RoamingDemon("Cinder", 5, 2, false, 2, Point2D(15, 5));

    mage_ptrs.push_back(mage1);
    mage_ptrs.push_back(mage2);
    spire_ptrs.push_back(spire1);
    spire_ptrs.push_back(spire2);
    hideout_ptrs.push_back(hideout1);
    hideout_ptrs.push_back(hideout2);
    roamingdemon_ptrs.push_back(demon1);
    roamingdemon_ptrs.push_back(demon2);

    object_ptrs.push_back(mage1);
    object_ptrs.push_back(mage2);
    object_ptrs.push_back(spire1);
    object_ptrs.push_back(spire2);
    object_ptrs.push_back(hideout1);
    object_ptrs.push_back(hideout2);
    object_ptrs.push_back(demon1);
    object_ptrs.push_back(demon2);

    active_ptrs = object_ptrs;

    cout << "Model default constructed" << endl;
}

Model::~Model()
{
    for (list<GameObject*>::iterator it = object_ptrs.begin(); it != object_ptrs.end(); it++) {
        // Deleting through the base pointer relies on GameObject's virtual destructor.
        delete *it;
    }
    cout << "Model destructed." << endl;
}

Mage* Model::GetMagePtr(int id)
{
    for (list<Mage*>::iterator it = mage_ptrs.begin(); it != mage_ptrs.end(); it++) {
        if ((*it)->GetId() == id) {
            return *it;
        }
    }
    return 0;
}

ManaSpire* Model::GetManaSpirePtr(int id)
{
    for (list<ManaSpire*>::iterator it = spire_ptrs.begin(); it != spire_ptrs.end(); it++) {
        if ((*it)->GetId() == id) {
            return *it;
        }
    }
    return 0;
}

DemonHideout* Model::GetDemonHideoutPtr(int id)
{
    for (list<DemonHideout*>::iterator it = hideout_ptrs.begin(); it != hideout_ptrs.end(); it++) {
        if ((*it)->GetId() == id) {
            return *it;
        }
    }
    return 0;
}

RoamingDemon* Model::GetRoamingDemonPtr(int id)
{
    for (list<RoamingDemon*>::iterator it = roamingdemon_ptrs.begin(); it != roamingdemon_ptrs.end(); it++) {
        if ((*it)->GetId() == id) {
            return *it;
        }
    }
    return 0;
}

void Model::NewCommand(char type, int id, Point2D location)
{
    GameObject* new_object = 0;

    // Model owns all object lists, is responsible for allocating and linking new objects
    // Each type has its own ID namespace, so duplicate checks stay type-specific.
    switch (type) {
        case 's': {
            if (GetManaSpirePtr(id) != 0) {
                throw Invalid_Input("Mana Spire ID already exists.");
            }
            ManaSpire* spire = new ManaSpire(id, 5, 100, location);
            spire_ptrs.push_back(spire);
            new_object = spire;
            break;
        }
        case 'd': {
            if (GetDemonHideoutPtr(id) != 0) {
                throw Invalid_Input("Demon Hideout ID already exists.");
            }
            DemonHideout* hideout = new DemonHideout(10, 1, 1.0, 2, id, location);
            hideout_ptrs.push_back(hideout);
            new_object = hideout;
            break;
        }
        case 'g': {
            if (GetMagePtr(id) != 0) {
                throw Invalid_Input("Mage ID already exists.");
            }
            // Runtime-created Mages use previous default speed and a generic name.
            Mage* mage = new Mage("Mage", id, 'M', 5, location);
            mage_ptrs.push_back(mage);
            new_object = mage;
            break;
        }
        case 'o': {
            if (GetRoamingDemonPtr(id) != 0) {
                throw Invalid_Input("Roaming Demon ID already exists.");
            }
            RoamingDemon* demon = new RoamingDemon("RoamingDemon", 5, 2, false, id, location);
            roamingdemon_ptrs.push_back(demon);
            new_object = demon;
            break;
        }
        default:
            throw Invalid_Input("Please enter a valid object type.");
    }

    // Newly created objects are owned by object_ptrs and immediately active.
    object_ptrs.push_back(new_object);
    active_ptrs.push_back(new_object);
    cout << "New object created." << endl;
}

bool Model::Update()
{
    bool event_happened = false;
    bool all_hideouts_passed = true;
    bool all_mages_knocked_out = true;

    time++;

    // active_ptrs contains the objects that are still updated each tick.
    for (list<GameObject*>::iterator it = active_ptrs.begin(); it != active_ptrs.end(); it++) {
        if ((*it)->Update()) {
            event_happened = true;
        }
    }

    // RoamingDemon::follow detects same-location contact starts a hunt.
    for (list<RoamingDemon*>::iterator demon_it = roamingdemon_ptrs.begin();
        demon_it != roamingdemon_ptrs.end(); demon_it++) {
        if (!(*demon_it)->IsAlive() || (*demon_it)->get_in_combat()) {
            continue;
        }

        for (list<Mage*>::iterator mage_it = mage_ptrs.begin(); mage_it != mage_ptrs.end(); mage_it++) {
            if (!(*mage_it)->IsKnockedOut()
                && (*demon_it)->GetLocation().x == (*mage_it)->GetLocation().x
                && (*demon_it)->GetLocation().y == (*mage_it)->GetLocation().y) {
                (*demon_it)->follow(*mage_it);
                event_happened = true;
                break;
            }
        }
    }

    // Remove dead or knocked-out objects from active_ptrs only; object_ptrs still owns them.
    for (list<GameObject*>::iterator it = active_ptrs.begin(); it != active_ptrs.end(); ) {
        if (!(*it)->ShouldBeVisible()) {
            cout << "Dead object removed." << endl;
            it = active_ptrs.erase(it);
        }
        else {
            it++;
        }
    }

    for (list<DemonHideout*>::iterator it = hideout_ptrs.begin(); it != hideout_ptrs.end(); it++) {
        if (!(*it)->passed()) {
            all_hideouts_passed = false;
        }
    }

    for (list<Mage*>::iterator it = mage_ptrs.begin(); it != mage_ptrs.end(); it++) {
        if (!(*it)->IsKnockedOut()) {
            all_mages_knocked_out = false;
        }
    }

    if (all_hideouts_passed) {
        cout << "GAME OVER: You win! All battles done!" << endl;
        exit(0);
    }

    if (all_mages_knocked_out) {
        cout << "GAME OVER: You lose! All of your Mages' mana is lost!" << endl;
        exit(0);
    }

    return event_happened;
}

void Model::Display(View& view)
{
    cout << "Time: " << time << endl;
    view.Clear();

    for (list<GameObject*>::iterator it = active_ptrs.begin(); it != active_ptrs.end(); it++) {
        view.Plot(*it);
    }

    view.Draw();
}

void Model::ShowStatus()
{
    cout << "Time: " << time << endl;
    for (list<GameObject*>::iterator it = object_ptrs.begin(); it != object_ptrs.end(); it++) {
        (*it)->ShowStatus();
    }
}
