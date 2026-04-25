#include <iostream>

#include "Building.h"
#include "DemonHideout.h"
#include "ManaSpire.h"

using namespace std;

int main()
{
    cout << "Building tests:" << endl;
    Building b1;
    cout << endl;
    Building b2('X', 2, Point2D(4, 5));
    cout << endl;
    b1.ShowStatus();
    b1.AddOneMage();
    b1.ShowStatus();
    b1.AddOneMage();
    b1.ShowStatus();
    b1.RemoveOneMage();
    b1.ShowStatus();

    cout << endl;
    cout << "ManaSpire tests:" << endl;
    ManaSpire s1;
    cout << endl;
    ManaSpire s2(3, 7.5, 4, Point2D(1, 2));
    cout << endl;
    s2.ShowStatus();
    cout << "Has crystals: " << s2.HasCrystals() << endl;
    cout << "Crystals remaining: " << s2.GetNumCrystalsRemaining() << endl;
    cout << "Cost for 3 crystals: " << s2.GetCrystalCost(3) << endl;
    cout << "Can afford 3 crystals with 25 gold: " << s2.CanAffordCrystal(3, 25) << endl;
    cout << "Distribute 2 crystals: " << s2.DistributeCrystals(2) << endl;
    cout << "Distribute 5 crystals: " << s2.DistributeCrystals(5) << endl;
    cout << "Update after depletion: " << s2.Update() << endl;
    cout << "Update again: " << s2.Update() << endl;
    s2.ShowStatus();

    cout << endl;
    cout << "DemonHideout tests:" << endl;
    DemonHideout d1;
    cout << endl;
    DemonHideout d2(3, 2, 4.5, 6, 8, Point2D(9, 1));
    cout << endl;
    d2.ShowStatus();
    cout << "Gold cost for 2 battles: " << d2.GetGoldCost(2) << endl;
    cout << "Mana cost for 2 battles: " << d2.GetManaCost(2) << endl;
    cout << "Battles remaining: " << d2.GetNumBattlesRemaining() << endl;
    cout << "Can battle 2 times with 10 gold and 5 mana: " << d2.IsAbleToBattle(2, 10, 5) << endl;
    cout << "Experience per battle: " << d2.GetExperiencePerBattle() << endl;
    cout << "Battle 2 units: " << d2.DemonBattle(2) << endl;
    cout << "Battle 5 units: " << d2.DemonBattle(5) << endl;
    cout << "Hideout passed: " << d2.passed() << endl;
    cout << "Update after defeat: " << d2.Update() << endl;
    cout << "Update again: " << d2.Update() << endl;
    d2.ShowStatus();

    return 0;
}
