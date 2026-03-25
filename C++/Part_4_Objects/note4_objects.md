# Objects

* operator overloading

Paradigm -> OOP (Objects-oriented Programming)
- Encapsulation
    - Public, Private, Protected

- Inheritance
    - Parents/ Children

- Polymorphism
    - "Dynamic Binding" at runtime

in C++
these are both objects
- struct 
    - public by default
- class
    - private by default


Object
- User Defined Datatype

Associating with objects
- Functions / Methods
- Variables


```cpp
class Circle {
    public: // as class is private by default, need public: to make it public to be use in main()

    // Member variable
    double radius;


    // default constructor
    // can only have one default constructor
    Circle() {
        radius = 1;
    }

    // can have many other constructors
    Circle(double newR) {
        radius = newR;
    }




    // Member functions
    double getArea() {
        return radius*radius*3.14;
    }

    void setRadius(double R) {
        // do stuff
        // can check if the radius is postive
    }

};

int main() {
    Circle c1(); // c1 is the instance of Circle
    double test = 2.1
    Circle c2(5.3);

    cout << c2.radius;
    cout << c2.getArea();
}

```


## Public & Private
- getters (Accessor)

- setters (Mutator)
```cpp
// setters that will check if the radius is positive
c2.setRadius(-13.5)
```



Functions that passes the class as the argument
```cpp
// copy constructor and pass by value
bool BigCircle(Circle c) {
    if (c.getArea() > 10)  {
        return true;
    }
    else {
        return false;
    }
}
```


## Operator Overloading

- Members
    - write in the class
    - private access
    - LHS & RHS
        - assumes LHS is class

- Non-Members
    - write outside of class
    - no private access
    - LHS & RHS
        - need to write both


Questions
1. Is the meaning clear?
2. stick semantics
3. "all of operators"

---------------

### Worksheet Example on Whale

[Worksheet Week 9 ](./Worksheet_W9_Objects_spr2026.pdf)

Whale.cpp
```cpp
class Whale
{
    public:
    double length;

    Whale() {
        blubber = 100;
        length = 110;
        species = “Blue”;
    }

    Whale (int b) {
        blubber = b;
    }

    void eat(int food) {
        blubber += food/10;
    }


    // const member function, function that does not change the member variables
    int getBlubber() const {
        // return blubber;
        return *this.blubber;
        return this -> blubber;
    }

    // member operator overloading
    Whale operator/ (Whale &whale2) {
        Whale returnWhale;
        returnWhale.length = length / whale2.length;
        return returnWhale;
    }

    private:
    int blubber;
    string species;
};

// non-member operator overloading 
Whale operator + (Whale &whale1, Whale &whale2) {
    return Whale(whale1.getBlubber() + whale2.getBlubber());
}


// :: is the Binary scope resolution operator
void Whale::eat(int food) {
    blubber += food/10;
}


Whale*  Whale::catchMe() {
    // 'this' is the pointer to itself
    return this;
}

```



main.cpp
```cpp
int main() {

    Whale willy;
    Whale billy(30);
    billy.length = 10;


    Whale Silly = willy + billy;
    Whale Lily = silly / willy;

    Whale* gilly;
    gilly = Lily.catchme();
    gilly = &billy;

    Whale * villy = new Whale;
    int bb = villy -> getBlubber();
}

```

## shallow copy VS deep copy
shallow copy
- two objects point to the same string array, (e.g. course with the same string array)

deep copy
- make a new array on the heap and then copy the original elements in the array to the new array
- Then, the object is deep copied from the other object






