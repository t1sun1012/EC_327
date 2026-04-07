#include <iostream>

#include "DemonHideout.h"

using namespace std;

// default constructor
DemonHideout::DemonHideout() : Building()
{
    display_code = 'D';
    state = NOT_DEFEATED;
    max_number_of_battles = 10;
    num_battle_remaining = max_number_of_battles;
    mana_cost_per_battle = 1;
    gold_cost_per_battle = 1.0;
    experience_per_battle = 2;
    cout << "DemonHideout default constructed" << endl;
}

// other constructor
DemonHideout::DemonHideout(unsigned int max_battle, unsigned int mana_loss, double cost,
    unsigned int exp_per_battle, int in_id, Point2D in_loc)
    : Building('D', in_id, in_loc)
{
    max_number_of_battles = max_battle;
    num_battle_remaining = max_number_of_battles;
    mana_cost_per_battle = mana_loss;
    gold_cost_per_battle = cost;
    experience_per_battle = exp_per_battle;
    state = NOT_DEFEATED;
    cout << "DemonHideout constructed" << endl;
}

// get gold cost
double DemonHideout::GetGoldCost(unsigned int battle_qty)
{
    return battle_qty * gold_cost_per_battle;
}

// get mana cost
unsigned int DemonHideout::GetManaCost(unsigned int battle_qty)
{
    return battle_qty * mana_cost_per_battle;
}

// get number of battles remaining
unsigned int DemonHideout::GetNumBattlesRemaining()
{
    return num_battle_remaining;
}

// is able to battle
bool DemonHideout::IsAbleToBattle(unsigned int battle_qty, double budget, unsigned int mana)
{
    return budget >= GetGoldCost(battle_qty) && mana >= GetManaCost(battle_qty);
}

// demon battle
unsigned int DemonHideout::DemonBattle(unsigned int battle_units)
{
    unsigned int battles_fought;

    if (battle_units <= num_battle_remaining) {
        battles_fought = battle_units;
    }
    else {
        battles_fought = num_battle_remaining;
    }

    num_battle_remaining -= battles_fought;
    return battles_fought * experience_per_battle;
}

// get experience per battle
unsigned int DemonHideout::GetExperiencePerBattle()
{
    return experience_per_battle;
}

// update
bool DemonHideout::Update()
{
    if (num_battle_remaining == 0 && state == NOT_DEFEATED) {
        state = DEFEATED;
        display_code = 'd';
        cout << "(" << display_code << ")(" << id_num << ") has been beaten" << endl;
        return true;
    }

    return false;
}

// passed
bool DemonHideout::passed()
{
    return num_battle_remaining == 0;
}

// show status
void DemonHideout::ShowStatus()
{
    cout << "DemonHideout Status: ";
    Building::ShowStatus();
    cout << "Max number of battles: " << max_number_of_battles << endl;
    cout << "Mana cost per battle: " << mana_cost_per_battle << endl;
    cout << "Gold per battle: " << gold_cost_per_battle << endl;
    cout << "Experience per battle: " << experience_per_battle << endl;
    cout << num_battle_remaining << " battle(s) are remaining for this DemonHideout" << endl;
}
