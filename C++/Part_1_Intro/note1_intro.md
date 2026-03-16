# C and C ++

C++ by Dennis Richie
Compiled Language

Text editor
- Vim

IDE 
- Syntax Highlight
- Linkser
- Better Debugger
- Integrations
    - Github

C++ 
plain text 
-> compiler (MIPS, x86, ARM)

-> Asm 

-> Assembler 

-> output Binary (Exe)

-> Linker connects libraries and main code

-> .exe

-> Loader

-> Memory


Compiled language is fast as it runs directly in the Memory

Why C++
- Standard
- Object Oriented (C++)
- Widely Used
- Pointers (C/C++)
    - Powerful
- Debugging

------------------------------------------------
Every C/C++ program starts in the main function


area.cpp

```C
// single line comment
/* 
multi-
line
comment
*/

#include <iostream> // import library iostream to use cout and endl
using namespace std; // 
int main() // main function takes no argument, nothing in (), return type defined before function name
{
    // type, varaible
   double radius;
   double area;
   radius = 20;
   // LHS = RHS, variable goes on the LHS
   area = radius * radius * 3.14;
   // Operator: + - * %
   cout <<"The area is " << area << endl;
   return 0;
}
```

Strongly types Language
int -> short, long
doubles -> float
char
bool


in Terminal
```
g++ area.cpp
./a
g++ -o test.exe area.cpp
./test
```



Example

```C++
int main()
{
    // Narrowing Examples
    double i = 1.7;
    int defaultCast = i; // 1
    int cStyleCast = (int)i; // C style Casting 1
    int staticCast = statis_cast<int>(i); // C++ style Casting

    // Widening Examples
    int j = 4;
    double staticCastDouble = static_cast<double>(j);
    cout << staticCastDouble << endl;
    cout << 1 / 2 << endl;
    cout << static_cast<double>(1) / 2 << endl;
  
    return 0;
}
```


