
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


# Standard Template Library (STL)
- 1994 C++ standard

1. Containers

linear
- array
- vector
- deque
- list
- forward list

Associative
- map
- multimap
- set
- multiset

Adaptive
- stack
- queue
- priority queue

2. Iterators
"Fancy" Pointers

3. Algorithm

4. Allocators
    - manage memory

### array<T,size>
fixed size array

```cpp
array<int,6> a {1,2,3,4,5,6};
// example
a.size();
a[2]; // 3

```



### vector<T>
dyanamic array
v 
1 2 3 4 5 6 ......

```cpp
vector<int> v {1,2,3,4,5,6,};
v.push_back(7);
v.pop_back();
v.erase(v.begin()+2);

```

### deque<T>
d
1 2 <-> 3 4 5 <-> 6

### list<T>
L
1 <-> 2 <-> 3 <-> 4 ... the back can point to the front

### forwardlist<T>
fL
1 -> 2 -> 3


## Iterator
```cpp
Iterator it v.begin();
cout << *it;
cout << *(it+2);
```

Iterator Type
- Random Access
- Bidirectional
- Forward
- Input
- Output


## Algorithms
example
sort()
find()

time complexity
O(1)
O(n)
O(nlogn)