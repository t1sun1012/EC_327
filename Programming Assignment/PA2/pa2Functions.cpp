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
    double pi = M_PI;
    return pi * pow(radius,2);
}

// return area of the square
double areaSquare(double length) {
    return length * length;
}

// return an odd number closet and higher to input number
int findNextOddValue(int number) {
    if (number % 2 == 0 ){
        return (number + 1);
    }
    else if (number % 2 == 1) {
        return (number + 2);
    }
}

// return an even number closet and higher to input number
int findNextEvenValue(int number) {
    if (number % 2 ==0) {
        return (number + 2);
    }
    else if (number % 2 == 1) {
        return (number + 1);
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
}

// return random number using system time and the argument
double lucky(double number) {
    // seed adding the argument and the system time, downcasting it to add
    srand(number + static_cast<double>(NULL));

    double result = rand();

    return result;

}

