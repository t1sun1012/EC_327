# PA3 Learning Summary

This programming assignment helped me learn how to build a larger C++ program step by step instead of trying to write everything at once. It started with simple data classes and gradually grew into a complete object-oriented program with interacting classes, a model, a controller, and a view.

## Main C++ Concepts I Learned

- Classes and objects: how to define classes in `.h` files and implement member functions in `.cpp` files.
- Constructors and destructors: how objects are initialized, how constructor chaining works with inheritance, and why destructors matter when cleaning up objects.
- Header and source separation: why declarations belong in header files and implementations belong in source files.
- Operator overloading: how `Point2D` and `Vector2D` can support `+`, `-`, `*`, `/`, and stream output to make the rest of the code cleaner.
- Pointers: how objects can store pointers to other objects, such as `Mage` storing pointers to `ManaSpire` and `DemonHideout`.
- The `->` operator: how to call member functions through pointers instead of direct objects.
- Dynamic memory: how `Model` creates objects with `new` and deletes them in its destructor.
- Virtual functions: how a base-class pointer can call the correct derived-class behavior through polymorphism.
- Pure virtual functions and abstract classes: how `GameObject` became an abstract base class that defines a shared interface for all game objects.

## Object-Oriented Programming Ideas I Learned

- Inheritance: `Building` inherits from `GameObject`, while `ManaSpire`, `DemonHideout`, and `Mage` build on top of shared base-class behavior.
- Encapsulation: each class owns its data and exposes functions that control how that data changes.
- Responsibility separation: each class has a clear job, such as `Mage` handling actions, `ManaSpire` handling crystals, and `DemonHideout` handling battles.
- State machines: `Mage` changes behavior depending on its current state, such as `STOPPED`, `MOVING`, `AT_SPIRE`, or `BATTLING_IN_HIDEOUT`.
- Object interaction: classes do not work alone; they collaborate by calling each other's functions.
- Code reuse: base classes provide shared data and behavior so derived classes do not repeat the same code.

## Software Design Lessons

- Iterative development: the assignment was much easier to understand when built checkpoint by checkpoint.
- MVC design: later checkpoints introduced the Model-View-Controller pattern:
  - `Model` stores and updates the game world
  - `GameCommand` acts as the controller
  - `View` displays the world
- Polymorphic updates: `Model` can store all objects as `GameObject*` and still call the right `Update()` function for each object type.
- Separation of concerns: game logic, command handling, and display logic should not all be mixed into one file or one class.

## What I Improved Overall

By the end of PA3, I had more practice writing a multi-file C++ program, designing class relationships, using inheritance and pointers correctly, and building a larger object-oriented system that behaves like a real software project instead of just a small isolated exercise.
