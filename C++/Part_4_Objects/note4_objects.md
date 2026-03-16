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






