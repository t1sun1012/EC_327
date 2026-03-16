#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

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
        cout << "cannot open output file" << endl;
        writetofile = false;
    }
    
    writetofile = true;
    cout << "Writing output to file: " << file << endl;

}

// read commands from a file
void readDataFromFile(const char *file) {

}

// return factorial value
int factorial(int);

// return the Fibonacci number
int fibonacci(int);

// return the square root
double findSqrtValue(double);

// return natural log
double naturalLog(double);

// return area of the circle
double areaCircle(double);

// return area of the square
double areaSquare(double);

// return an odd number closet and higher to input number
int findNextOddValue(int);

// return an even number closet and higher to input number
int findNextEvenValue(int);

// special NyanCat function
double findNyanCatValue(double);

// sin, cosine or exponential function
double doMath(double, char);

// return random number using system time and the argument
double lucky(double);

