

// find median
double getMedian(int arr[], int size) {
    int sort_arr[1000];
    for (int i = 0; i < size; i++) {
        sort_arr[i] = arr[i];
    }


    // sort the array
    for (int i = 0; i< size - 1; i++) {
        for (int j = 0; j< size -1 -i; j++){
            if (sort_arr[j] > sort_arr[j + 1]) {
                int value = sort_arr[j];
                sort_arr[j] = sort_arr[j +1];
                sort_arr[j + 1] = value;
            }
        }
    }


    // find the median

    // for odd number of elements 
    if (size % 2 == 1){
        return (sort_arr[size/2]);
    }

    // for even number of elemets, average of the middle two elements
    else {
        return (sort_arr[size / 2 -1] + sort_arr[size / 2]) / 2.0;
    }


}


// find maxmum
int getLargest(int arr[], int size) {
    int sort_arr[1000];
    for (int i = 0; i < size; i++) {
        sort_arr[i] = arr[i];
    }


    // sort the array
    for (int i = 0; i< size - 1; i++) {
        for (int j = 0; j< size -1 -i; j++){
            if (sort_arr[j] > sort_arr[j + 1]) {
                int value = sort_arr[j];
                sort_arr[j] = sort_arr[j +1];
                sort_arr[j + 1] = value;
            }
        }
    }

    // return the last element of the sorted array
    return sort_arr[size -1];
}
