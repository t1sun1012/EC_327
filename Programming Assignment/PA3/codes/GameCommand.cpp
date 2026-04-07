#include <iostream>

#include "GameCommand.h"

using namespace std;

void DoMoveCommand(Model& model, int mage_id, Point2D p1)
{
    Mage* mage = model.GetMagePtr(mage_id);

    // validate through Model, then forward to the target object
    if (mage != 0) {
        cout << "Moving " << mage->GetName() << " to " << p1 << endl;
        mage->StartMoving(p1);
    }
    else {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoMoveToSpireCommand(Model& model, int mage_id, int spire_id)
{
    Mage* mage = model.GetMagePtr(mage_id);
    ManaSpire* spire = model.GetManaSpirePtr(spire_id);

    if (mage != 0 && spire != 0) {
        cout << "Moving " << mage->GetName() << " to Mana Spire " << spire_id << endl;
        mage->StartMovingToSpire(spire);
    }
    else {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoMoveToHideoutCommand(Model& model, int mage_id, int hideout_id)
{
    Mage* mage = model.GetMagePtr(mage_id);
    DemonHideout* hideout = model.GetDemonHideoutPtr(hideout_id);

    if (mage != 0 && hideout != 0) {
        cout << "Moving " << mage->GetName() << " to hideout " << hideout_id << endl;
        mage->StartMovingToHideout(hideout);
    }
    else {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoStopCommand(Model& model, int mage_id)
{
    Mage* mage = model.GetMagePtr(mage_id);

    if (mage != 0) {
        cout << "Stopping " << mage->GetName() << endl;
        mage->Stop();
    }
    else {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoBattleCommand(Model& model, int mage_id, unsigned int battles)
{
    Mage* mage = model.GetMagePtr(mage_id);

    if (mage != 0) {
        cout << mage->GetName() << " is battling" << endl;
        mage->StartBattling(battles);
    }
    else {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoRecoverInSpireCommand(Model& model, int mage_id, unsigned int crystals_needed)
{
    Mage* mage = model.GetMagePtr(mage_id);

    if (mage != 0) {
        cout << "Recovering " << mage->GetName() << "'s mana" << endl;
        mage->StartRecoveringMana(crystals_needed);
    }
    else {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoAdvanceCommand(Model& model, View& view)
{
    cout << "Advancing one tick." << endl;
    model.Update();
    model.Display(view);
}

void DoRunCommand(Model& model, View& view)
{
    bool event_happened = false;

    cout << "Advancing to next event." << endl;

    // Run stops on the first reported event or after five ticks.
    for (int i = 0; i < 5; i++) {
        event_happened = model.Update();
        model.Display(view);
        if (event_happened) {
            break;
        }
    }
}
