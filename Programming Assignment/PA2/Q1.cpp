#include <iostream>
#include <cmath>

#include "pa2Functions.h"

using namespace std;


// global variable, maximum calculations setted for this program
extern const int ENTRIES = 10;

// helper function for single integer command codes
int input_parameter_integer() {
    cout << "Please enter command parameters:" << endl;

    int integer;
    cin >> integer;

    return integer;
}


// helper function for double command codes
double input_parameter_double() {
    cout << "Please enter command parameters:" << endl;

    double first; double last; double delta;
    cin >> first >> last >> delta;


    // determine special cases
    if (delta <= 0 || first > last) {
        cout << "No computation needed." << endl;
    }
    else {
        // determine computation counts and first, last in range
        for (int count = 0; first <= last && count != ENTRIES; count++) {
            first += delta;
        }
        if (first > last) {
            return last;
        }
        else {
            return first;
        }
    }
}

// helper function for reading files
char* input_parameter_file() {
    cout << "Please enter command parameters:" << endl;

    char* file;
    cin >> file;

    return file;
}




main() {
    // initialize command code variable
    char command;


    //
    while (command != 'Q' && command != 'q') {
        cout << 'Please enter command code:' << endl;
        cin >> command;

        if (checkCode(command)) {
            switch (command) {
            case 'F':
            case 'f':
                // factorial
                int number = input_parameter_integer();
                cout << factorial(number) << endl;
                break;

            case 'B':
            case 'b':
                // Fibonacci
                int number = input_parameter_integer();
                cout << fibonacci(number) << endl;
                break;

            case 'R':
            case 'r':
                // square root
                double number = input_parameter_double();
                cout << findSqrtValue(number) << endl;
                break;

            case 'U':
            case 'u':
                // area of Square
                double number = input_parameter_double();
                cout << areaCircle(number) << endl;
                break;

            case 'C':
            case 'c':
                // area of Circle
                double number = input_parameter_double();
                cout << areaSquare(number) << endl;
                break;

            case 'E':
            case 'e':
                // list even numbers in the range of first and last
                cout << "Please enter command parameters:" << endl;
                double first; double last;
                cin >> first >> last;

                // check if first is smaller than last 
                if (first > last) {
                    cout << "No computation needed." << endl;
                }

                else {
                    for (int current = first ; current <= last;){
                        current = findNextEvenValue(current);
                        cout << current << endl;
                    } 
                }
                break;



            case 'K':
            case 'k':
                // generate random number
                double number = input_parameter_double();
                cout << lucky(number) << endl;
                break;

            case 'S':
            case 's':
                // compute sin values
                double number = input_parameter_double();
                cout << doMath(number,'s') << endl;
                break;

            case 'N':
            case 'n':
                // compute cosine values
                double number = input_parameter_double();
                cout << doMath(number, 'n') << endl;
                break;

            case 'X':
            case 'x':
                // compute exponentials
                double number = input_parameter_double();
                cout << doMath(number, 'x') << endl;
                break;

            case 'L':
            case 'l':
                // compute natural logs
                double number = input_parameter_double();
                cout << naturalLog(number) <<endl;
                break;

            case 'Y':
            case 'y':
                // compute NyanCat value
                double number = input_parameter_double();
                cout << findNyanCatValue(number) << endl;
                break;

            case 'D':
            case 'd':
                // list Odd numbers in the range of first and last
                cout << "Please enter command parameters:" << endl;
                double first; double last;
                cin >> first >> last;

                // check if first is smaller than last
                if (first > last) {
                    cout << "No computation needed." << endl;
                }
                else {
                    for (int current = first ; current <= last;){
                        current = findNextOddValue(current);
                        cout << current << endl;
                    } 
                }
                break;


            case 'I':
            case 'i':
                // to do, read from input file
                break;

            case 'O':
            case 'o':
                // write to output file
                char* file = input_parameter_file();
                writeDataToFile(file);
                break;

            default:
                cout << "Invalid command code" << endl;
                break;

            }
        }
        else {
            cout << "Invalid command code" << endl;
        }
        
    }
}