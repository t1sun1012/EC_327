#include <iostream>
using namespace std;


int main() {
    cout << "Start = ";
    int start;
    cin >> start;

    cout << "End = ";
    int end;
    cin >> end;

    cout << "Step = ";
    int step;
    cin >> step;

    if (start != end) {
        cout << start;
        if (start < end){
            for (int increment = start + step; increment <= end; increment += step){
            cout << "," << increment;
            }
        }
        else {
            for (int increment= start- step;increment >= end; increment -= step) {
            cout << "," << increment;
            }
        }
        
    }

    else {
        cout << "See you later!" << endl;
    }
}