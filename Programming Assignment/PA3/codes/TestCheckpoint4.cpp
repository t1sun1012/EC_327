#include <iostream>

#include "GameCommand.h"
#include "Model.h"

using namespace std;

class View {
};

int main()
{
    Model model;
    View view;

    model.ShowStatus();
    cout << endl;

    DoMoveToHideoutCommand(model, 1, 1);
    DoRunCommand(model, view);
    DoRunCommand(model, view);
    DoBattleCommand(model, 1, 2);
    DoAdvanceCommand(model, view);
    cout << endl;

    DoMoveToSpireCommand(model, 2, 2);
    DoRunCommand(model, view);
    DoRunCommand(model, view);
    DoRecoverInSpireCommand(model, 2, 1);
    DoAdvanceCommand(model, view);
    cout << endl;

    DoMoveCommand(model, 1, Point2D(2, 2));
    DoStopCommand(model, 1);
    DoMoveCommand(model, 99, Point2D(0, 0));
    cout << endl;

    model.ShowStatus();

    return 0;
}
