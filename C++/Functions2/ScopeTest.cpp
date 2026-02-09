#include <iostream>  
 
using namespace std;  /* outermost level of scope starts here */
 
int i;
 
int main(){               /* next level of scope starts here */
  int i;
  i = 5;
 
  while(i != 5) {     /* next level of scope starts here */
    int j,i;
    j = 1;
    i = 0;
    switch (i) {      /* next level of scope starts here */
      int i;
 
      case 1:
        if (i != 4) { /* innermost level of scope of this program starts here */
          int k, i;
          i = -1;
          j = 6;
          k = 2;
        }             /* innermost level of scope of this program ends here */
        break;
 
      case 2: 
        j = 5;
        break;
    }                 /* next level of scope ends here */
    cout << j << ' ';
  }                   /* next level of scope ends here */
 
  cout << i << endl;
  
  return 0;
} 
