#include <iostream>

#include "DemonHideout.h"
#include "Mage.h"
#include "ManaSpire.h"

using namespace std;

int main()
{
    cout << "Stage 1: constructors and status" << endl;
    Mage m1;
    m1.ShowStatus();
    cout << endl;

    Mage m2('m');
    m2.ShowStatus();
    cout << endl;

    Mage gandalf("Gandalf", 3, 'G', 2, Point2D(0, 0));
    gandalf.ShowStatus();
    cout << endl;

    cout << "Stage 2: plain movement" << endl;
    gandalf.StartMoving(Point2D(5, 0));
    gandalf.ShowStatus();
    while (!gandalf.Update()) {
        gandalf.ShowStatus();
    }
    gandalf.ShowStatus();
    cout << endl;

    cout << "Stage 3: spire and hideout travel" << endl;
    ManaSpire spire(1, 0, 3, Point2D(5, 5));
    DemonHideout hideout(2, 1, 0, 4, 2, Point2D(8, 5));

    gandalf.StartMovingToSpire(&spire);
    while (!gandalf.Update()) {
        gandalf.ShowStatus();
    }
    gandalf.ShowStatus();
    spire.ShowStatus();
    cout << endl;

    cout << "Stage 4: recover mana" << endl;
    gandalf.StartRecoveringMana(2);
    gandalf.Update();
    gandalf.ShowStatus();
    cout << endl;

    cout << "Stage 5: battle in hideout" << endl;
    gandalf.StartMovingToHideout(&hideout);
    while (!gandalf.Update()) {
        gandalf.ShowStatus();
    }
    gandalf.ShowStatus();
    spire.ShowStatus();
    hideout.ShowStatus();
    gandalf.StartBattling(5);
    gandalf.Update();
    gandalf.ShowStatus();
    hideout.ShowStatus();
    cout << endl;

    cout << "Stage 6: knockout behavior" << endl;
    Mage merlin("Merlin", 4, 'R', 1, Point2D(0, 0));
    merlin.StartMoving(Point2D(30, 0));
    for (int i = 0; i < 25; i++) {
        merlin.Update();
    }
    merlin.ShowStatus();

    return 0;
}
