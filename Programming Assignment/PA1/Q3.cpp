#include <iostream>
using namespace std;

int main() {
    // ask the users for input
    cout << "Enter two numbers between 0-100:";
    int number1;
    cin >> number1;
    int number2;
    cin >> number2;

    // initialize quotients and hamming_distance
    int hamming_distance;
    int quotient1;
    int quotient2;
    int remainder1;
    int remainder2;


    // initialize quotient to numbers and for loop will continue if either quotient1 or quotient2 is not zero. meaning to finish the find remainder process untill both quotients are zero.
    for (quotient1 = number1, quotient2 = number2; (quotient1 != 0) || (quotient2 != 0);) {
        remainder1 = quotient1 % 3;
        remainder2 = quotient2 % 3;

        quotient1 = quotient1 / 3;
        quotient2 = quotient2 / 3;
        
        // compare remainder, if not equal, hamming_distance +1
        if (remainder1 != remainder2) {
            hamming_distance++;
        }
    }

    cout << "Hamming distance between " << number1 << " and " <<  number2 << " when numbers are in ternary format is: " << hamming_distance << endl;
}