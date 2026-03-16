#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>


#include "pa2Functions.h"

using namespace std;


// global variable, maximum calculations setted for this program
const int ENTRIES = 10;

extern ofstream OutFile;
extern bool writetofile;

// helper function for single integer command codes
int input_parameter_integer() {
    cout << "Please enter command parameters:" << endl;

    int integer;
    cin >> integer;

    return integer;
}



int main() {

    initialize(); // initialize

    // initialize command code variable
    char command = '\0';


    while (command != 'Q' && command != 'q') {
        cout << "Please enter command code:" << endl;
        cin >> command;

        if (checkCode(command)) {
            switch (command) {
            case 'F':
            case 'f':{
                // factorial
                int number_f = input_parameter_integer();
                cout << factorial(number_f) << endl;
                if (writetofile) {
                    OutFile << factorial(number_f) << endl;
                }
                break;
            }

            case 'B':
            case 'b':{
                // Fibonacci
                int number_b = input_parameter_integer();
                cout << fibonacci(number_b) << endl;
                if (writetofile) {
                    OutFile << fibonacci(number_b) << endl;
                }
                break;
            }


            //cases for doubles that need first, last and delta
            case 'R':
            case 'r':
            case 'U':
            case 'u':
            case 'C':
            case 'c':
            case 'K':
            case 'k':
            case 'S':
            case 's':
            case 'N':
            case 'n':
            case 'X':
            case 'x':
            case 'L':
            case 'l':
            case 'Y':
            case 'y': {
                cout << "Please enter command parameters:" << endl;
                double first, last, delta;
                cin >> first >> last >> delta;

                if (delta <= 0 || first > last) {
                    cout << "No computation needed." << endl;
                    if (writetofile) {
                        OutFile << "No computation needed." << endl;
                    }
                    break;
                }

                int count = 0;
                double current = first;
                while (count < ENTRIES) {
                    double number = current;
                    if (number > last) {
                        number = last;
                    }
                    double result = 0.0;
                    char cmd = tolower(static_cast<unsigned char>(command));

                    if (cmd == 'r') result = findSqrtValue(number);
                    else if (cmd == 'u') result = areaSquare(number);
                    else if (cmd == 'c') result = areaCircle(number);
                    else if (cmd == 'k') result = lucky(number);
                    else if (cmd == 's') result = doMath(number, 's');
                    else if (cmd == 'n') result = doMath(number, 'n');
                    else if (cmd == 'x') result = doMath(number, 'x');
                    else if (cmd == 'l') result = naturalLog(number);
                    else if (cmd == 'y') result = findNyanCatValue(number);

                    cout << result << endl;
                    if (writetofile) {
                        OutFile << result << endl;
                    }

                    if (number >= last) break;
                    current += delta;
                    count++;
                }
                break;
            }

           

            

      
            case 'E':
            case 'e': {
                cout << "Please enter command parameters:" << endl;
                int first_e, last_e;
                cin >> first_e >> last_e;

                if (first_e > last_e) {
                    cout << "No computation needed." << endl;
                    if (writetofile) {
                        OutFile << "No computation needed." << endl;
                    }
                } else {
                    int current_e = first_e;
                    // if first is odd, use the function to get the next even
                    if (current_e % 2 != 0) {
                        current_e = findNextEvenValue(current_e - 1);
                    }
                    while (current_e <= last_e) {
                        cout << current_e << endl;
                        if (writetofile) {
                            OutFile << current_e << endl;
                        }
                        current_e = findNextEvenValue(current_e);
                    }
                }
                break;
            }


            case 'D':
            case 'd': {
                cout << "Please enter command parameters:" << endl;
                int first_d, last_d;
                cin >> first_d >> last_d;

                if (first_d > last_d) {
                    cout << "No computation needed." << endl;
                    if (writetofile) {
                        OutFile << "No computation needed." << endl;
                    }
                } else {
                    int current_d = first_d;
                    // if first is even, use the function to get the next odd
                    if (current_d % 2 == 0) {
                        current_d = findNextOddValue(current_d - 1);
                    }
                    while (current_d <= last_d) {
                        cout << current_d << endl;
                        if (writetofile) {
                            OutFile << current_d << endl;
                        }
                        current_d = findNextOddValue(current_d);
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
                break;
            }
            }
        }
        else {
            cout << "Invalid command code" << endl;
            if (writetofile) {
                    OutFile << "Invalid command code" << endl;
            }
        }
        
    }
}