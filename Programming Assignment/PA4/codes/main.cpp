#include <iostream>

#include "GameCommand.h"
#include "Model.h"
#include "View.h"

using namespace std;

void HandleCommand(char command, Model& model, View& view);

int main()
{
    Model model;
    View view;
    char command;

    // Show the initial object state once before the command loop starts
    model.ShowStatus();
    model.Display(view);

    while (cin >> command) {
        if (command == 'q') {
            break;
        }

        HandleCommand(command, model, view);
    }

    return 0;
}

void HandleCommand(char command, Model& model, View& view)
{
    int id1;
    int id2;
    double x;
    double y;
    unsigned int amount;

    switch (command) {
        case 'm':
            cin >> id1 >> x >> y;
            DoMoveCommand(model, id1, Point2D(x, y));
            break;
        case 's':
            cin >> id1 >> id2;
            DoMoveToSpireCommand(model, id1, id2);
            break;
        case 'd':
            cin >> id1 >> id2;
            DoMoveToHideoutCommand(model, id1, id2);
            break;
        case 'h':
            cin >> id1;
            DoStopCommand(model, id1);
            break;
        case 'c':
            cin >> id1 >> amount;
            DoRecoverInSpireCommand(model, id1, amount);
            break;
        case 'b':
            cin >> id1 >> amount;
            DoBattleCommand(model, id1, amount);
            break;
        case 'a':
            DoAdvanceCommand(model, view);
            break;
        case 'r':
            DoRunCommand(model, view);
            break;
        default:
            cout << "Error: Please enter a valid command!" << endl;
            break;
    }
}
