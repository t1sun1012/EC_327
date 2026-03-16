#include <iostream>
#include <fstream>
#include <ctime>


#include "FileFunctions.h"
#include "Statistics.h"

using namespace std;



int *DoubleAndReverse (int *list, int size) {
    int *array = new int[2*size]; // create a new array with doubled size on the heap

    // copy original values
    for (int i = 0; i < size; i++) {
        array[i] = list[i];
    }

    for (int i = 0; i < size; i++) {
        array[size + i] = list[size - 1 - i];
    }

    return array;
}


int main() {

    

    // read file into an array
    int myArray[1000];
    int size = 0;
    cout << "Reading file: data.txt" << endl;
    ReadData("data.txt", size, myArray);

    // create data file
    cout << "Writing file: data.txt" << endl;
    WriteRandomData(5, 10, "data.txt");

    // print the size
    cout << "Array size is: " << size << endl;



    //initialize a new array
    int *new_arr = DoubleAndReverse(myArray, size);


    // print double and reverse array
    cout << "Doubled and reversed is [";
    for (int i = 0; i< 2 * size; i++) {
        cout << new_arr[i];
        if (i < 2* size -1) {
            cout << " ";
        }
    }
    cout << "]" << endl;


    // calculate median and largest number
    cout << "Median is: " << getMedian(new_arr, 2*size) << endl;
    cout << "Largest is: " << getLargest(new_arr, 2*size) << endl;
    
    delete[] new_arr;

}