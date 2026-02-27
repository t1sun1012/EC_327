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
    cout << ptest << endl;

    
    cout << reverse(ptest) << endl;
}




int word_length(char* str) {
    int length;
    for (length = 0; str[length] != '\0' ; length ++);
    return length;
}


void reverse_inplace(char* str) {
    int length = word_length(str) - 1;

    char temp;

    for (int i = 0, j = length; i < (length+1) ; i++, j-- ) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}


char* reverse(char* str) {
    int length = word_length(str) - 1;

    //new string on the heap to store the result, same length as original string
    char *result = new char[length]; 

    
    for (int i = 0, j = length; i < (length +1); i++, j--) {
        result[j] = str[i];
    }
    return result;
}
