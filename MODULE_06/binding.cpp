# include <iostream>
# include <string>
# include <iomanip>
# include <cmath>
# include <cstdlib>
# include <ctime>

// Binding in C++ refers to the process of associating a function call with the actual code that should be executed at runtime. There are two main types of binding in C++: compile-time binding (also known as static binding) and runtime binding (also known as dynamic binding).

// 1. Compile-Time Binding (Static Binding):
// Compile-time binding occurs when the association between a function call and the corresponding code is determined at compile time. This type of binding is typical for non-virtual functions and functions called on objects using the dot operator.

// Here's how it works:

// Function Overloading:

// In C++, compile-time binding is achieved through function overloading and function templates.
// The compiler determines the correct function to call based on the number and types of arguments in the function call.
// cpp
void print(int x) {
    // ...
}

void print(double y) {
    // ...
}

int main() {
    int a = 42;
    double b = 3.14;

    print(a);  // Calls print(int)
    print(b);  // Calls print(double)

    return 0;
}

// Templates:

// Function templates provide another form of compile-time polymorphism.
// The compiler generates specific instances of the template for different types at compile time.
// cpp
// Copy code
template <typename T>
void print(T value) {
    // ...
}

int main() {
    int a = 42;
    double b = 3.14;

    print(a);  // Calls print<int>(int)
    print(b);  // Calls print<double>(double)

    return 0;
}
// 2. Runtime Binding (Dynamic Binding):
// Runtime binding occurs when the association between a function call and the corresponding code is determined at runtime. This type of binding is typical for virtual functions and functions called on objects using pointers or references.

// Here's how it works:

// Virtual Functions and Dynamic Dispatch:

// In C++, runtime binding is achieved through virtual functions and dynamic dispatch.
// When a function is declared as virtual in the base class, and it is overridden in derived classes, the correct function to call is determined at runtime based on the actual type of the object.
// cpp
// Copy code
class Base {
public:
    virtual void print() {
        // ...
    }
};

class Derived : public Base {
public:
    void print() override {
        // ...
    }
};

int main() {
    Base* ptr = new Derived;
    ptr->print();  // Calls Derived::print at runtime

    delete ptr;
    return 0;
}
// Virtual Table (vtable) and Virtual Pointer (vptr):

// Under the hood, when a class has virtual functions, the compiler typically generates a virtual table (vtable).
// Each object of a class with virtual functions contains a hidden virtual pointer (vptr) that points to the vtable.
// The vtable holds pointers to the actual implementations of the virtual functions for that class.
// When calling a virtual function through a base class pointer, the vptr is used to determine the correct function to call at runtime.
// cpp
// Copy code
// Simplified representation of vtable and vptr
class Base {
public:
    virtual void print() {
        // ...
    }
};

class Derived : public Base {
public:
    void print() override {
        // ...
    }
};

int main() {
    Base* ptr = new Derived;
    ptr->print();  // Calls Derived::print at runtime

    delete ptr;
    return 0;
}
// The actual details of how vtables and vptrs are implemented can vary between different compilers and platforms.