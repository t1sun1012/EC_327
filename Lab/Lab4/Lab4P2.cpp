#include <iostream>
#include <cmath>

#include "countHeads.h"

using namespace std;

int main() {

    char again = 'y';
    while (again = 'y') {
    cout << "how many coins would you like to flip? ";
    int N;
    cin >> N;

    cout << "How many heads fo you want? ";
    int r;
    cin >> r;

    int result = static_cast<int>(ceil(choose(N,r)));
    cout << "Flipping " << N << " coins, we can get " << r << " heads " << result << " ways" << endl;

    cout << "Flip again? ";
    cin >> again;
    if (again == 'n') {
        break;
    }

    }
}
