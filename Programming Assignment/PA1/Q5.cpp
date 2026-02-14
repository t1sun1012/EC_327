#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

int main() {
    // prompt the user to enter a letter
    cout << "Enter a letter: ";
    char letter;
    cin >> letter;

    // convert the letter to uppercase
    letter = toupper(letter);

    // switch statement to handle the case when the letter is 'Z'
    switch (letter) {
        case 'Z':
            letter = letter -26;
        default:
            letter += 1;
    }

    // check if the letter is a letter
    if (isalpha(letter)) {
        cout << "CRYPTO: " << letter << endl;
    }
    else {
        cout << "YOU DID NOT ENTER A LETTER" << endl;
    }
    
}