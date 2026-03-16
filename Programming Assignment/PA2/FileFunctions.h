#ifndef FILEFUNCTIONS_H

#define FILEFUNCTIONS_H

// generate random data to a file
void WriteRandomData(int N, int M, const char *filename);

// find the size of the elements in the file
void ReadData(const char *filename, int &size, int myArray[]);


#endif

