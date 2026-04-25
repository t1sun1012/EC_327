#include <iostream>
#include <limits>

#include "GameCommand.h"
#include "Input_Handling.h"
#include "Model.h"
#include "View.h"

using namespace std;

void HandleCommand(char command, Model& model, View& view);
int GetInt();
double GetDouble();
unsigned int GetUnsignedInt();

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

        try {
            // All input validation errors thrown below are handled in one place.
            HandleCommand(command, model, view);
        }
        catch (Invalid_Input& except) {
            cout << "Invalid input - " << except.msg_ptr << endl;
            // Reset the stream and discard the rest of the bad command line.
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
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
            id1 = GetInt();
            x = GetDouble();
            y = GetDouble();
            DoMoveCommand(model, id1, Point2D(x, y));
            break;
        case 's':
            id1 = GetInt();
            id2 = GetInt();
            DoMoveToSpireCommand(model, id1, id2);
            break;
        case 'd':
            id1 = GetInt();
            id2 = GetInt();
            DoMoveToHideoutCommand(model, id1, id2);
            break;
        case 'h':
            id1 = GetInt();
            DoStopCommand(model, id1);
            break;
        case 'c':
            id1 = GetInt();
            amount = GetUnsignedInt();
            DoRecoverInSpireCommand(model, id1, amount);
            break;
        case 'b':
            id1 = GetInt();
            amount = GetUnsignedInt();
            DoBattleCommand(model, id1, amount);
            break;
        case 'a':
            DoAdvanceCommand(model, view);
            break;
        case 'r':
            DoRunCommand(model, view);
            break;
        default:
            throw Invalid_Input("Please enter a valid command.");
            break;
    }
}

int GetInt()
{
    int input;

    // Read first, then throw if the stream could not parse the expected type.
    if (!(cin >> input)) {
        throw Invalid_Input("Was expecting an integer.");
    }

    return input;
}

double GetDouble()
{
    double input;

    if (!(cin >> input)) {
        throw Invalid_Input("Was expecting a number.");
    }

    return input;
}

unsigned int GetUnsignedInt()
{
    int input = GetInt();

    // Read as signed first so negative values can be rejected cleanly.
    if (input < 0) {
        throw Invalid_Input("Was expecting a non-negative integer.");
    }

    return static_cast<unsigned int>(input);
}
