#include <iostream>
#include <cstdlib>

#include "Model.h"
#include "View.h"

using namespace std;

Model::Model()
{
    time = 0;

    // Build the default world described
    mage_ptrs[0] = new Mage("Serena", 1, 'M', 1, Point2D(5, 1));
    mage_ptrs[1] = new Mage("Rumi", 2, 'M', 2, Point2D(10, 1));
    spire_ptrs[0] = new ManaSpire(1, 1, 100, Point2D(1, 20));
    spire_ptrs[1] = new ManaSpire(2, 2, 200, Point2D(10, 20));
    hideout_ptrs[0] = new DemonHideout(10, 1, 2, 3, 1, Point2D(0, 0));
    hideout_ptrs[1] = new DemonHideout(20, 5, 7.5, 4, 2, Point2D(5, 5));
    // adds two default RoamingDemons to the world.
    roamingdemon_ptrs[0] = new RoamingDemon("Ash", 5, 2, false, 1, Point2D(10, 12));
    roamingdemon_ptrs[1] = new RoamingDemon("Cinder", 5, 2, false, 2, Point2D(15, 5));

    // Every object appears once in array and once in its typed lookup array.
    object_ptrs[0] = mage_ptrs[0];
    object_ptrs[1] = mage_ptrs[1];
    object_ptrs[2] = spire_ptrs[0];
    object_ptrs[3] = spire_ptrs[1];
    object_ptrs[4] = hideout_ptrs[0];
    object_ptrs[5] = hideout_ptrs[1];
    object_ptrs[6] = roamingdemon_ptrs[0];
    object_ptrs[7] = roamingdemon_ptrs[1];

    num_objects = 8;
    num_mages = 2;
    num_spires = 2;
    num_hideouts = 2;
    num_roamingdemons = 2;

    cout << "Model default constructed" << endl;
}

Model::~Model()
{
    for (int i = 0; i < num_objects; i++) {
        // Deleting through the base pointer relies on GameObject's virtual destructor.
        delete object_ptrs[i];
    }
    cout << "Model destructed." << endl;
}

Mage* Model::GetMagePtr(int id)
{
    for (int i = 0; i < num_mages; i++) {
        if (mage_ptrs[i]->GetId() == id) {
            return mage_ptrs[i];
        }
    }
    return 0;
}

ManaSpire* Model::GetManaSpirePtr(int id)
{
    for (int i = 0; i < num_spires; i++) {
        if (spire_ptrs[i]->GetId() == id) {
            return spire_ptrs[i];
        }
    }
    return 0;
}

DemonHideout* Model::GetDemonHideoutPtr(int id)
{
    for (int i = 0; i < num_hideouts; i++) {
        if (hideout_ptrs[i]->GetId() == id) {
            return hideout_ptrs[i];
        }
    }
    return 0;
}

RoamingDemon* Model::GetRoamingDemonPtr(int id)
{
    for (int i = 0; i < num_roamingdemons; i++) {
        if (roamingdemon_ptrs[i]->GetId() == id) {
            return roamingdemon_ptrs[i];
        }
    }
    return 0;
}

bool Model::Update()
{
    bool event_happened = false;
    bool all_hideouts_passed = true;
    bool all_mages_knocked_out = true;

    time++;

    // send Update() to the correct derived type for each object
    for (int i = 0; i < num_objects; i++) {
        if (object_ptrs[i]->Update()) {
            event_happened = true;
        }
    }

    // RoamingDemon::follow detects same-location contact starts a hunt.
    for (int i = 0; i < num_roamingdemons; i++) {
        if (!roamingdemon_ptrs[i]->IsAlive() || roamingdemon_ptrs[i]->get_in_combat()) {
            continue;
        }

        for (int j = 0; j < num_mages; j++) {
            if (!mage_ptrs[j]->IsKnockedOut()
                && roamingdemon_ptrs[i]->GetLocation().x == mage_ptrs[j]->GetLocation().x
                && roamingdemon_ptrs[i]->GetLocation().y == mage_ptrs[j]->GetLocation().y) {
                roamingdemon_ptrs[i]->follow(mage_ptrs[j]);
                event_happened = true;
                break;
            }
        }
    }

    for (int i = 0; i < num_hideouts; i++) {
        if (!hideout_ptrs[i]->passed()) {
            all_hideouts_passed = false;
        }
    }

    for (int i = 0; i < num_mages; i++) {
        if (!mage_ptrs[i]->IsKnockedOut()) {
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

    for (int i = 0; i < num_objects; i++) {
        view.Plot(object_ptrs[i]);
    }

    view.Draw();
}

void Model::ShowStatus()
{
    cout << "Time: " << time << endl;
    for (int i = 0; i < num_objects; i++) {
        object_ptrs[i]->ShowStatus();
    }
}
