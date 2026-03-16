#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include "pa2Functions.h"

using namespace std;



// print program output header
void initialize() {
    cout << "EC327: Introduction to Software Engineering" << endl;
    cout << "Spring 2026" << endl;
    cout << "Programming Assignment 2" << endl;
    cout << "Value of Entries is: " << ENTRIES << endl;
}

// check if user inputs of command codes are valid
bool checkCode(char command) {
    // convert to lowercase
    command = static_cast<char>(tolower(static_cast<unsigned char>(command)));

    // check validity of command code
    if (command == 'f' || command == 'b' || command == 'r'
        || command == 'u' || command == 'c' || command == 'e' ||
        command == 'k' || command == 's' || command == 'n' || command == 'x' || 
        command == 'l' || command == 'y' || command == 'd' || command == 'i' ||
        command == 'o' || command == 'q') {
            return true;
        }
    else {
        return false;
    }
}



ofstream OutFile; // control output file
bool writetofile = false;

// write the output of the program to a file, 
void writeDataToFile(const char *file) {

    if (OutFile.is_open()) {
        OutFile.close();
    }


    OutFile.open(file); // open the output file


    if (!OutFile) {
        cout << "cannot open output file:" << endl;
        writetofile = false;
        return;
    }

    writetofile = true;
    cout << "Writing output to file: " << file << endl;
    OutFile << "Writing output to file" << file << endl;

}

// read commands from a file
void readDataFromFile(const char *file) {
    ifstream InFile(file);

    // determine if input file is valid
    if (!InFile) {
        cout << "cannot open input file" << endl;
        return;
    }

    // initialize command
    char command;

    // reading the command and parameters from the input file
    while (InFile >> command) {
        if (!checkCode(command)) {
        
            cout << "Invalid command code" << endl;

            // write the output to the file
            if (writetofile) {
                OutFile << "Invalid command code" << endl;
            }

            continue;
        }

        // exit the program when command is Q or q
        if (command == 'Q' || command == 'q') {
            break;
        }


        // case by case command
        switch (command) {
            // factorial
            case 'F':
            case 'f': {
                int n;
                InFile >> n;
                int result = factorial(n);
                cout << result << endl;
                if (writetofile) {
                    OutFile << result << endl;
                }
                break;
            }


            // fibonacci
            case 'B':
            case 'b': {
                int n;
                InFile >> n;
                int result = fibonacci(n);
                cout << result << endl;
                if (writetofile) {
                    OutFile << result << endl;
                }
                break;
            }


            // cases where input parameters are first, last, delta
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
                // assign parameters to variables from input file
                double first, last, delta;
                InFile >> first >> last >> delta;
                

                // special cases, invalid delta and first and last
                if (delta <= 0 || first > last) {
                    cout << "No computation needed." << endl;
                    if (writetofile) {
                        OutFile << "No computation needed." << endl;
                    }
                    break;
                }

                // initiailize count and compare it with ENTRIES
                int count = 0;
                double current = first;


                
                while (count < ENTRIES) {
                    double number = current;
                    // if adding delta larger than last, treat last as the input parameter
                    if (number > last) {
                        number = last;
                    }

                    double result = 0.0;

                    if (command == 'R' || command == 'r') result = findSqrtValue(number);
                    else if (command == 'U' || command == 'u') result = areaSquare(number);
                    else if (command == 'C' || command == 'c') result = areaCircle(number);
                    else if (command == 'K' || command == 'k') result = lucky(number);
                    else if (command == 'S' || command == 's' ||
                             command == 'N' || command == 'n' ||
                             command == 'X' || command == 'x') result = doMath(number, command);
                    else if (command == 'L' || command == 'l') result = naturalLog(number);
                    else if (command == 'Y' || command == 'y') result = findNyanCatValue(number);

                    cout << result << endl;
                    if (writetofile) {
                        OutFile << result << endl;
                    }

                    if (number == last) {
                        break;
                    }


                    // current number adding delta and increment count
                    current += delta;
                    count++;
                }
                break;
            }


            // find even number in the range of first and last
            case 'E':
            case 'e': {
                int first, last;
                InFile >> first >> last;

                if (first > last) {
                    cout << "No computation needed." << endl;
                    if (writetofile) {
                        OutFile << "No computation needed." << endl;
                    }
                } else {
                    int current = first;
                    if (current % 2 != 0) {
                        current++;
                    }
                    while (current <= last) {
                        cout << current << endl;
                        if (writetofile) {
                            OutFile << current << endl;
                        }
                        current += 2;
                    }
                }
                break;
            }


            // find odd number in the range of first and last
            case 'D':
            case 'd': {
                int first, last;
                InFile >> first >> last;

                if (first > last) {
                    cout << "No computation needed." << endl;
                    if (writetofile) {
                        OutFile << "No computation needed." << endl;
                    }
                } else {
                    int current = first;
                    
                    if (current % 2 == 0) {
                        current++;
                    }
                    while (current <= last) {
                        cout << current << endl;
                        if (writetofile) {
                            OutFile << current << endl;
                        }
                        current += 2;
                    }
                }
                break;
            }

            case 'O':
            case 'o': {
                char file[100];
                InFile >> file;
                writeDataToFile(file);
                break;
            }

            case 'I':
            case 'i': {
                char file[100];
                InFile >> file;
                readDataFromFile(file);
                break;
            }
        }
    }

    InFile.close();
}

// return factorial value
int factorial(int n)
{
  if (n == 0) // Base case
    return 1;
  else
    return n * factorial(n - 1); // Recursive call
}


// return the Fibonacci number
int fibonacci(int index) {
  if (index == 0) // Base case
    return 0;
  else if (index == 1) // Base case
    return 1;
  else // Reduction and recursive calls
    return fibonacci(index - 1) + fibonacci(index - 2);

}

// return the square root
double findSqrtValue(double value) {
    double result = sqrt(value);
    return result;
}

// return natural log
double naturalLog(double value) {
    double result = log(value);
    return result;
}

// return area of the circle
double areaCircle(double radius) {
    double pi = 3.14;
    return pi * pow(radius,2);
}

// return area of the square
double areaSquare(double length) {
    return length * length;
}

// return an odd number closet and higher to input number
int findNextOddValue(int number) {
    if (number % 2 == 0 ){
        return number + 1;
    }
    else {
        return number + 2;
    }
}

// return an even number closet and higher to input number
int findNextEvenValue(int number) {
    if (number % 2 ==0) {
        return number + 2;
    }
    else {
        return number + 1;
    }
}

// special NyanCat function
double findNyanCatValue(double myNum) {
    return (pow((4 * myNum), myNum) + myNum + 10);
}

// sin, cosine or exponential function
double doMath(double number, char command) {
    switch (command) {
        case 'S':
        case 's':
            return sin(number);
            break;
        
        case 'N':
        case 'n':
            return cos(number);
            break;

        case 'X':
        case 'x':
            return exp(number);
            break;
    }
    return 0;
}

// return random number using system time and the argument
double lucky(double number) {
    // seed adding the argument and the system time, downcasting it to add
    srand(number + static_cast<double>(NULL));

    double result = rand();

    return result;

}

