# Arrays & Pointers

## Pointers
```cpp
int count = 5;
short status = 2;
char letter = 'A';

```




```cpp
double radius = 5;



Defensive Programming
// 1
// make the pointer constant
double *const pvalue = &radius;

// 2
// point to something is constant
const double * pvalue = &radius;


// cannot be changed in case 2
*pvalue = 6;


// cannot be changed in case 1
double foo = 100;
pvalue = &foo;

```


### C-style String
w

o

r

d

special character to end the string

char *foo = "word";


## Arrays

Data Structures
- make algorithm fast
- intuitive

Stack -> push,pop -> LIFO
Queue -> enQ, deQ -> FIFO
Array



```cpp
const int SIZE = 10; // conventionally and prefer const to construct array
int list [SIZE];


int amount = 10; // but also ok to do without const
int myList [amount];
```

list is empty at first, need to fill it up using loop

```cpp
for(int = 0 ; i<10 ; i++){
    cout << list[i]
}
```


```cpp
void procArray(int, int[]);

procArray(10, list)

```


1. pass an array to a function is pass by reference to the array
2. Array is a pointer





Strongly Type Language
- Data Types
    - Int, Double
- User-Defined Types
    - classes
        - objects

Pass by referecne
referecne and pointers



```cpp
int myList[4] = {1,2,3,4};
// myList by itself is int*

myList[1] == *(myList+1) // same thing
```
Arrays are pointers


