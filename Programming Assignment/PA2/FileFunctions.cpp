#include <fstream>
#include <ctime>

using namespace std;

ofstream outFile;

ifstream inFile;

// generate random data to a file
void WriteRandomData(int N, int M, const char *filename) {

    outFile.open(filename); 
    srand(time(NULL));

    for (int count = 0 ; count != N ; count ++) {
        int random_num = rand() % (M+1);
        outFile << random_num << endl;
    }

    outFile.close();
}



// find the size of the elements in the file
void ReadData(const char *filename, int &size, int myArray[]) {
    inFile.open(filename);

    size = 0; // initialize size to be 0

    int value; 
    while(inFile >> value) {
        myArray[size] = value; // store the value
        size++;                 // increment count
    }

    inFile.close();
}