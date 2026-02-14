#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

int main() {
    cout << "Enter a letter: ";
    char letter;
    cin >> letter;


    letter = toupper(letter);

    switch (letter) {
        case 'Z':
            letter = letter -26;
        default:
            letter += 1;
    }

    if (isalpha(letter)) {
        cout << "CRYPTO: " << letter << endl;
    }
    else {
        cout << "YOU DID NOT ENTER A LETTER" << endl;
    }
    
}