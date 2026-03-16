#include <iostream>

using namespace std;


int * ReverseMultiply(int *list, int size);

int * ReverseAdd(int *list, int size);


int * ReverseMultiply(int *list, int size) {

    // initialize an array on the heap
    int* result_arr = new int[size*2 +1];

    // copy elements in the original array to the new array
    for (int index = 0; index < size; index++) {
        result_arr[index] = list[index];
    }

    // fill the other half of the new array with reverse order of original elements
    for (int index = 0; index < size; index++) {
        result_arr[size + index] = list[size - 1 - index];
    }


    // initialize the last element of the new array to be 1
    result_arr[size*2] = 1;

    // fill the last element with the product of the previous elements
    for (int index = 0 ; index < size*2; index++) {
        result_arr[size*2] *= result_arr[index];
    }

    return result_arr;
}

int * ReverseAdd(int *list, int size) {
    // initialize a new array on the heap
    int * result_arr = new int[2*size - 1];

    // copy elements in the original array to the new array
    for (int index = 0; index < size; index++) {
        result_arr[index] = list[index];
    }

    // fill the rest of the elements with the addition of the two elemets
    for (int index = 0; index < size -1; index++) {
        result_arr[size + index] = list[size - 1 - index] + list[size - 2 - index];
    }

    return result_arr;
}


int main() {
    // prompt the user to enter the size of the array
    cout << "Enter the number of entries: ";
    int size;
    cin >> size;


    // initialize an array with input size
    int arr[size];

    // prompt the user for entries and assign it in the array created
    for (int index = 0; index < size; index++) {
        cout << "Entry " << index << " is: ";
        int element;
        cin >> element;
        arr[index] = element;
        cout << arr[index];
    }




    // print each element in the array
    cout << "Original array is: ";
    for (int index = 0; index < size; index++) {
        cout <<  arr[index] << " ";
    }

    // print the address of the array
    cout << "and the address of the zero element is: " << arr << endl;




    // One array using ReverseMultipy
    int * multi_arr = ReverseMultiply(arr, size);

    // print each element in the array after ReverseMultiply
    cout << "One array is: ";
    for (int index = 0; index < size*2 + 1; index++) {
        cout <<  multi_arr[index] << " ";
    }

    // print address of the array after ReverseMultiply
    cout << "and the address of zero element is: " << multi_arr << endl;






    // two array using ReverseAdd
    int * add_arr = ReverseAdd(arr, size);

    // print each element in the array after ReverseAdd
    cout << "Two array is: ";
    for (int index = 0; index < size*2 - 1; index++) {
        cout <<  add_arr[index] << " ";
    }
    // print the address of the array after ReverseAdd
    cout << "and the address of zero element is: " << add_arr << endl;
    

}