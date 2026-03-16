#include <iostream>
using namespace std;

int main()
{
  int a[10] = {0,10,20,30,40,50,60,70,80,90}; 
  int *ip = a;
  printf("%d ", a[0]);
  printf("%d ", *(ip));
  printf("%d ", *(ip + 1));
  printf("%d ", *ip++);
  printf("%d ", *ip);
  printf("%d ", *(ip+3));
  printf("%d \n", *(ip-1));
  /*
  SOLUTION
  ip = a;
  printf("%d ", a[1]);
  printf("%d ", *(ip + 1));
  printf("%d ", *(ip + 2));
  printf("%d ", *++ip);
  printf("%d ", *++ip);
  printf("%d ", *(ip+3));
  printf("%d \n", *(ip-1));
  */
  return 0;
}


/*

Note: The reason why it needs to be printed one by one is because the
  I/O interface doesn't interact correctly with the OS. This is the easiest way 
  to correct it and it doesn't affect the pointer aspect of this problem.


-Change the elements being printed (a[0], *(ip), etc.) so that the output is now 
  (10 10 20 10 20 50 10).  Try to do this with minimal changes, such as a[0] to a[1]. 
  printf("%d ", a[1]);
  printf("%d ", *(ip + 1));
  printf("%d ", *(ip + 2));
  printf("%d ", *++ip);
  printf("%d ", *++ip);
  printf("%d ", *(ip+3));
  printf("%d \n", *(ip-1));
  
-Write code to determine the size of the integer pointer data type. 
  printf("\n size of data type pointer = %d ", sizeof(ip));

-What happens when you print the pointer values themselves?  You might want to use %x instead of %d to 
  get the values in hex (why?).  Why is the difference between ip and ip+1 not 1? 
  printf("\n value of pointer = %x ", ip);
  printf("\n value of pointer+1 = %x ", ip+1);
  You want to print in hex because you're printing out a memory address,
    which is going to be a huge decimal number. 
  The difference between ip and ip+1 is because you're incrementing by a word. 
    ^- This is probably out of the scope of this course.
*/
