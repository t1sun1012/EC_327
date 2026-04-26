#ifndef DEMONHIDEOUT_H
#define DEMONHIDEOUT_H

#include <iostream>

#include "Building.h"

using namespace std;

// enum for the states of the DemonHideout
enum DemonHideoutStates {
    NOT_DEFEATED = 0,
    DEFEATED = 1
};

// inheritance from public Building
class DemonHideout : public Building {
    private:
    unsigned int num_battle_remaining;
    unsigned int max_number_of_battles;
    unsigned int mana_cost_per_battle;
    double gold_cost_per_battle;
    unsigned int experience_per_battle;

    public:
    // default constructor
    DemonHideout();

    // other constructor
    DemonHideout(unsigned int max_battle, unsigned int mana_loss, double cost,
        unsigned int exp_per_battle, int in_id, Point2D in_loc);

    ~DemonHideout() override;

    double GetGoldCost(unsigned int battle_qty);
    unsigned int GetManaCost(unsigned int battle_qty);
    unsigned int GetNumBattlesRemaining();
    bool IsAbleToBattle(unsigned int battle_qty, double budget, unsigned int mana);
    unsigned int DemonBattle(unsigned int battle_units);
    unsigned int GetExperiencePerBattle();
    bool Update() override;
    bool passed();
    void ShowStatus() override;
    void save(ofstream& file) override;
    void restore(ifstream& file, Model& model) override;
};

#endif
