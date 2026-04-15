# Algorithms

Algorithms:
- correct
- performance
    - Space(memory)
    - Time
        - Operations (Big O)
        - "Wall clock"(Real Time application)
    


## Sorting

### Bubble Sort
2 9 5 4 8 1

compare 9 and 2 and not swap

2 9 5 4 8 1 

compare 9 and 5 and swap

2 5 9 4 8 1

compare 9 and 4 and swap

2 5 4 9 8 1 

compare 9 and 8 and swap

2 5 4 8 9 1

compare 9 and 1 and swap

2 5 4 8 1 9 


n- 1 comparison <- pass 1 -> 6 n
n- 2 comparison <- pass 2 -> 5 n - 1
n- 3 comparison <- pass 3 -> 4 n - 2
...

(n-1) + n-2 + n-3 + ... + 2 + 1 = 
(n-1)*n / 2

Time complexity
O (n^2)

### Merge Sort
2 9 5 4 8 1 6 7 

divide 

2 9 5 4           8 1 6 7

divide

2 9      5 4        8 1         6 7


conquer
29   45      18      67

2459        1678

12456789

O(nlogn)

### Quick Sort
- 1962 C.A.R Hoare

see hand-writting notes

Best case: O(nlogn)
Worst case: O(n^2)
Average case: O(nlogn)

#### Quick sort VS Merge sort

Although quick sort has slower time complexity in worst case, it took lower space complexity.

But merge sort use recursion to implement in code (more function calls), making it slower in real time.


### Heap Sort
- Binary Tree (complete)
    - Parent is greater than any children

- Why heap sort even it is slower:
    - easy to add new element


see hand-writting notes