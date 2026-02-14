#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;

int main() {
    // request input from the user
    cout << "Choose Fire (0), Water(1), or Grass (2):";
    int user_choice;
    cin >> user_choice;

    srand(time(nullptr)); // let the random generate number vary with time


    // generate random number between 0,1,2
    int range = 2-0 +1;
    int computer_choice = rand() % range + 0;


    // match different user choices with different computer choices
    switch (user_choice) {
        case 0:
            switch (computer_choice) {
                case 0:
                cout << "Computer chooses: Fire" << endl;
                cout << "You tie!" << endl;
                break;

                case 1:
                cout << "Computer chooses: Water" << endl;
                cout << "You lose!" << endl;
                break;

                case 2:
                cout << "Computer chooses: Grass" << endl;
                cout << "You win!" << endl;
                break;
            }
        break;

        case 1:
            switch (computer_choice) {
                case 0:
                cout << "Computer chooses: Fire" << endl;
                cout << "You win!" << endl;
                break;

                case 1:
                cout << "Computer chooses: Water" << endl;
                cout << "You tie!" << endl;
                break;

                case 2:
                cout << "Computer chooses: Grass" << endl;
                cout << "You loss!" << endl;
                break;
            }
        break;

        case 2:
            switch (computer_choice) {
                case 0:
                cout << "Computer chooses: Fire" << endl;
                cout << "You lose!" << endl;
                break;

                case 1:
                cout << "Computer chooses: Water" << endl;
                cout << "You win!" << endl;
                break;

                case 2:
                cout << "Computer chooses: Grass" << endl;
                cout << "You tie!" << endl;
                break;
            }
        break;
    }
}
