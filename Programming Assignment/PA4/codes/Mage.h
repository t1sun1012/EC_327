#ifndef MAGE_H
#define MAGE_H

#include <iostream>
#include <string>

#include "GameObject.h"

using namespace std;

class ManaSpire;
class DemonHideout;
class RoamingDemon;

enum MageStates {
    STOPPED = 0,
    MOVING = 1,
    KNOCKED_OUT = 2,
    AT_SPIRE = 3,
    IN_HIDEOUT = 4,
    MOVING_TO_SPIRE = 5,
    MOVING_TO_HIDEOUT = 6,
    BATTLING_IN_HIDEOUT = 7,
    RECOVERING_MANA = 8
};

class Mage : public GameObject {
    private:
    double speed;
    bool is_at_spire;
    bool is_in_hideout;
    unsigned int mana;
    unsigned int experience;
    double gold_pieces;
    unsigned int battles_to_buy;
    unsigned int crystals_to_buy;
    string name;
    // These pointers track the building the Mage is currently interacting with.
    ManaSpire* current_spire;
    DemonHideout* current_hideout;
    // set when a RoamingDemon has started following this Mage
    RoamingDemon* current_demon;
    // destination is the target point; delta is the movement step per update.
    Point2D destination;
    Vector2D delta;

    protected:
    bool UpdateLocation();
    void SetupDestination(Point2D dest);
    // Centralizes the movement of mana cost plus the new RoamingDemon penalty.
    void LoseMovementMana();

    public:
    Mage();
    Mage(char in_code);
    Mage(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc);
    ~Mage() override;

    void StartMoving(Point2D dest);
    void StartMovingToHideout(DemonHideout* hideout);
    void StartMovingToSpire(ManaSpire* spire);
    void StartBattling(unsigned int num_battles);
    void StartRecoveringMana(unsigned int num_crystals);
    void Stop();
    bool IsKnockedOut();
    bool ShouldBeVisible() override;
    void ShowStatus() override;
    bool Update() override;
    string GetName();
    // Called by RoamingDemon::follow after Model detects contact.
    void StartBeingFollowed(RoamingDemon* demon);
    bool HasRoamingDemon();
};

double GetRandomAmountOfGP();

#endif
