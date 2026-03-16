#ifndef PA2FUNCTIONS_H

#define PA2FUNCTIONS_H

// print program output header
void initialize();

// check if user inputs of command codes are valid
bool checkCode(char);

// write the output of the program to a file, 
void writeDataToFile(const char *);

// read commands from a file
void readDataFromFile(const char *);

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



#endif