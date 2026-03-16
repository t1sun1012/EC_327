#include <fstream>
#include <ctime>

using namespace std;

ofstream outFile;

ifstream inFile;

// generate random data to a file
void WriteRandomData(int N, int M, const char *filename) {
    outFile.open(filename);
    for (int count = 0 ; count != N ; count ++) {
        srand(static_cast<double>(NULL));
        int random_num = rand() % (M+1);
        outFile << random_num << endl;
    }
}



// find the size of the elements in the file
void ReadData(const char *filename, int &size, int myArray[]) {
    inFile.open(filename);

    int position = 0;

    int value; 
    while(inFile >> value) {
        myArray[position] = value; // store the value
        position++;                 // increment count
    }
}