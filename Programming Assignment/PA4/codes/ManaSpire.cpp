#include <iostream>

#include "ManaSpire.h"

using namespace std;

// default constructor
ManaSpire::ManaSpire() : Building()
{
    display_code = 'S';
    crystal_capacity = 100;
    num_crystals_remaining = crystal_capacity;
    cost_per_crystal = 5;
    state = CRYSTALS_AVAILABLE;
    cout << "ManaSpire default constructed" << endl;
}

// other constructor
ManaSpire::ManaSpire(int in_id, double crystal_cost, unsigned int crystal_cap, Point2D in_loc)
    : Building('S', in_id, in_loc)
{
    crystal_capacity = crystal_cap;
    num_crystals_remaining = crystal_capacity;
    cost_per_crystal = crystal_cost;
    state = CRYSTALS_AVAILABLE;
    cout << "ManaSpire constructed" << endl;
}

ManaSpire::~ManaSpire()
{
    cout << "ManaSpire destructed." << endl;
}

// has crystals
bool ManaSpire::HasCrystals()
{
    return num_crystals_remaining > 0;
}

// get number of crystals remaining
unsigned int ManaSpire::GetNumCrystalsRemaining()
{
    return num_crystals_remaining;
}

// can afford crystal
bool ManaSpire::CanAffordCrystal(unsigned int crystal, double budget)
{
    return budget >= GetCrystalCost(crystal);
}

// get crystal cost
double ManaSpire::GetCrystalCost(unsigned int crystal)
{
    return crystal * cost_per_crystal;
}

// distribute crystals
unsigned int ManaSpire::DistributeCrystals(unsigned int crystals_needed)
{
    unsigned int crystals_distributed;

    if (num_crystals_remaining >= crystals_needed) {
        num_crystals_remaining -= crystals_needed;
        crystals_distributed = crystals_needed;
    }
    else {
        crystals_distributed = num_crystals_remaining;
        num_crystals_remaining = 0;
    }

    return crystals_distributed;
}

// update
bool ManaSpire::Update()
{
    if (num_crystals_remaining == 0 && state == CRYSTALS_AVAILABLE) {
        state = NO_CRYSTALS_AVAILABLE;
        display_code = 's';
        cout << "ManaSpire " << id_num << " has ran out of crystals." << endl;
        return true;
    }

    return false;
}

// show status
void ManaSpire::ShowStatus()
{
    cout << "ManaSpire Status: ";
    Building::ShowStatus();
    cout << "Gold pieces per crystal: " << cost_per_crystal << endl;
    cout << "has " << num_crystals_remaining << " crystal(s) remaining." << endl;
}
