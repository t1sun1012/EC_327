
## Function Pointer
Von Neumann
FuncPtr -> Instruction 
ptr -> Data


```cpp
int foo(); // declare/ prototype
foo(); //call

int *pFoo(); // function returns ptr
int (*ptrFoo)(); // Function ptr
```

```cpp
int foo();

int (*pfoo)();

pfoo = foo;

// -----------------------------

int hoo(int x);

int (*phoo)(int) = hoo;

hoo(10);

phoo(10);


// specify the user which function to use
int specialSort(_, int (*sort)(int));

specialSort(_, phoo);
```

## Type Def
