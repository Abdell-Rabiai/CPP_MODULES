// static_cast in c++

#include <iostream>
#include <string>

using namespace std;


// case 1: static_cast on primitive types
// it performs implicit conversions between types

int main(){
    float f = 3.14f;
    int a;

    a = f; // this is an implicit conversion
    a = static_cast<int>(f); // this is an explicit conversion
    // those are equivalent, but the second one is more explicit and readable and searchable
    return 0;
}

// case 3 : static_cast on pointers is more restrictive than C-style cast 
// it performs implicit conversions between pointers

int main() {
    char c;
    int *p = (int *)&c; // passes at compile time but it will fail at runtime.
    *p = 42;

    int *x = static_cast<int *>(&c); // This will FAIL to compile : not compatible pointer types (int* and char*)
    return 0;
}

// case 4: static_cast on all upcasts but never and not recommended for downcasts

class base {};
class derived : public base {};
class derived2 : public base {};

int main(){
    derived d1;
    derived2 d2;

    base *b1 = static_cast<base *>(&d1); // upcast : this is ok0 :
    base *b2 = static_cast<base *>(&d2); // upcast : this is ok0

    derived *d3 = static_cast<derived *>(b1); // downcast : this is not ok
    derived2 *d4 = static_cast<derived2 *>(b1); // downcast : this is not ok
    return 0;
}


// case 5: static_cast on void * pointers

int main(){
    int i = 42;
    void *v = &i;
    int *p = static_cast<int *>(v); // this is ok
    return 0;
}