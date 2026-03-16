#include <iostream>
#include <fstream>
#include <sstream>
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
        return 0;
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
            case 'f':{
                // factorial
                int number_f = input_parameter_integer();
                cout << factorial(number_f) << endl;
                break;
            }

            case 'B':
            case 'b':{
                // Fibonacci
                int number_b = input_parameter_integer();
                cout << fibonacci(number_b) << endl;
                break;
            }

            case 'R':
            case 'r': {
                // square root
                double number_r = input_parameter_double();
                cout << findSqrtValue(number_r) << endl;
                break;
            }

            case 'U':
            case 'u': {

    
                // area of Square
                double number_u = input_parameter_double();
                cout << areaSquare(number_u) << endl;
                break;
            }

            case 'C':
            case 'c': {

                // area of Circle
                double number_c = input_parameter_double();
                cout << areaCircle(number_c) << endl;
                break;
            }

            case 'E':
            case 'e': {
                // list even numbers in the range of first and last
                cout << "Please enter command parameters:" << endl;
                double first_e; double last_e;
                cin >> first_e >> last_e;

                // check if first is smaller than last 
                if (first_e > last_e) {
                    cout << "No computation needed." << endl;
                }

                else {
                    for (int current_e = first_e ; current_e <= last_e;){
                        current_e = findNextEvenValue(current_e);
                        cout << current_e << endl;
                    } 
                }
                break;
            }


            case 'K':
            case 'k': {
            
                // generate random number
                double number_k = input_parameter_double();
                cout << lucky(number_k) << endl;
                break;
            }

            case 'S':
            case 's': {

                // compute sin values
                double number_s = input_parameter_double();
                cout << doMath(number_s,'s') << endl;
                break;
            }

            case 'N':
            case 'n': {
                // compute cosine values
                double number_n = input_parameter_double();
                cout << doMath(number_n, 'n') << endl;
                break;
            }

            case 'X':
            case 'x': {
                // compute exponentials
                double number_x = input_parameter_double();
                cout << doMath(number_x, 'x') << endl;
                break;
            }

            case 'L':
            case 'l': {
                // compute natural logs
                double number_l = input_parameter_double();
                cout << naturalLog(number_l) <<endl;
                break;
            }


            case 'Y':
            case 'y': {
                // compute NyanCat value
                double number_y = input_parameter_double();
                cout << findNyanCatValue(number_y) << endl;
                break;
            }

            case 'D':
            case 'd': {
            
                // list Odd numbers in the range of first and last
                cout << "Please enter command parameters:" << endl;
                double first_d; double last_d;
                cin >> first_d >> last_d;

                // check if first is smaller than last
                if (first_d > last_d) {
                    cout << "No computation needed." << endl;
                }
                else {
                    for (int current_d = first_d ; current_d <= last_d;){
                        current_d = findNextOddValue(current_d);
                        cout << current_d << endl;
                    } 
                }
                break;
            }

            case 'I':
            case 'i': {
                // read from input file
                char infile[100];
                cout << "Please enter command parameters:" << endl;
                cin >> infile;
                readDataFromFile(infile);
                break;
            }

            case 'O':
            case 'o': {

                // write to output file
                char outfile[100];
                cout << "Please enter command parameters:" << endl;
                cin >> outfile;
                writeDataToFile(outfile);
                break;
            }

            default: {
                cout << "Invalid command code" << endl;
                break;
            }
            }
        }
        else {
            cout << "Invalid command code" << endl;
        }
        
    }
}