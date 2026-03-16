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
const char* input_parameter_file() {
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
                // to do, factorial
                break;

            case 'B':
            case 'b':
                // to do, Fibonacci
                break;

            case 'R':
            case 'r':
                // to do, square root
                break;

            case 'U':
            case 'u':
                // to do, area of Square
                break;

            case 'C':
            case 'c':
                // to do, area of Circle
                break;

            case 'E':
            case 'e':
                // to do, even numbers
                cout << "Please enter command parameters:" << endl;
                double first; double last; double delta;
                cin >> first >> last >> delta;




                break;



            case 'K':
            case 'k':
                // to do, Lucky number, generate random number
                break;

            case 'S':
            case 's':
                // to do, compute sin values
                break;

            case 'N':
            case 'n':
                // to do, compute cosine values
                break;

            case 'X':
            case 'x':
                // to do, compute exponentials
                break;

            case 'L':
            case 'l':
                // to do, compute natural logs
                break;

            case 'Y':
            case 'y':
                // to do, compute NyanCat value
                break;

            case 'D':
            case 'd':
                // to do, Odd numbers
                cout << "Please enter command parameters:" << endl;
                double first; double last; double delta;
                cin >> first >> last >> delta;





                break;



            case 'I':
            case 'i':
                // to do, read from input file
                break;

            case 'O':
            case 'o':
                // to do, write to output file
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