#include<iostream>
using namespace std;

int main() {
    cout << "What number would you like to check?";
    int input;
    cin >> input;
    
    if (input > 0) {

        int count = 0;

        for (int divider = 1; divider <= input ; divider++) {
            if (input % divider == 0 ){
                count += 1;
                cout << divider << ",";
            }
        }
        cout << endl;

        if (count == 2) {
            cout << "This number is prime!" << endl;
        }
        else {
            cout << "This number is not prime!" << endl;
        }
    } 

    else {
        cout << "I dont't deal with negativity!" << endl;
    }
}