#include <iostream>

using namespace std;

// fucntion return the length of the string
int word_length(char* str);

// function reverse the order of the original string
void reverse_inplace(char* str);

// function make a copy and reverse the copied string
char* reverse(char* str);




int main() {
    // test for the functions
    char test[] = "function";

    char *ptest;
    ptest = &test[0];

    
    cout << word_length(ptest) << endl;

    reverse_inplace(ptest);
    cout << test << endl;

    char* r = reverse(ptest);
    cout << r << endl;
    delete[] r;

    return 0;
}



int word_length(char* str) {
    int length;
    for (length = 0; str[length] != '\0' ; length ++);
    return length;
}


void reverse_inplace(char* str) {
    int length = word_length(str) - 1;

    char temp;

    for (int i = 0, j = length; i < j ; i++, j-- ) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}


char* reverse(char* str) {
    // real length is without the null \0
    int length = word_length(str);

    //new string on the heap to store the result, same length as original string but +1 to include \0
    char *result = new char[length + 1]; 

    
    for (int i = 0; i < length; i++) {
        result[length -1 -i] = str[i];
    }
    result[length] = '\0';
    return result;
}
