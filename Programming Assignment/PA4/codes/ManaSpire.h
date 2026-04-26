#ifndef MANASPIRE_H
#define MANASPIRE_H

#include <iostream>

#include "Building.h"

using namespace std;

// enum for the states of the ManaSpire
enum ManaSpireStates {
    CRYSTALS_AVAILABLE = 0,
    NO_CRYSTALS_AVAILABLE = 1
};

// inheritance from public Building
class ManaSpire : public Building {
    private:
    unsigned int crystal_capacity;
    unsigned int num_crystals_remaining;
    double cost_per_crystal;

    public:
    // default constructor
    ManaSpire();

    // other constructor
    ManaSpire(int in_id, double crystal_cost, unsigned int crystal_cap, Point2D in_loc);

    ~ManaSpire() override;

    // has crystals
    bool HasCrystals();

    // get number of crystals remaining
    unsigned int GetNumCrystalsRemaining();
    bool CanAffordCrystal(unsigned int crystal, double budget);
    double GetCrystalCost(unsigned int crystal);
    unsigned int DistributeCrystals(unsigned int crystals_needed);
    bool Update() override;
    void ShowStatus() override;
    void save(ofstream& file) override;
    void restore(ifstream& file, Model& model) override;
};

#endif
