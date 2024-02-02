// dynamic_cast in c++

#include <iostream>
#include <string>

using namespace std;

// case 1: dynamic_cast on pointers that are polymorphic types
// meaning that they have at least one virtual function

class base {
    public:
        virtual void print() {
            cout << "base" << endl;
        }
};

class derived1 : public base {
    public:
        void print() override {
            cout << "derived1" << endl;
        }
};

class derived2 : public base {
    public:
        void print() override {
            cout << "derived2" << endl;
        }
};

int main() {
    base *b = new derived1;
    // base *b = new base();
    b->print();

    // dynamic_cast will check if the pointer can be casted to the type
    // if it can, it will return a pointer to the type
    // if it can't, it will return a nullptr
    //! down casting this is not always valid and it will return a nullptr
    derived1 *d1 = dynamic_cast<derived1 *>(b);
    if (d1) {
        d1->print(); 
    }
    else {
        cout << "d1 is nullptr" << endl;
    }

    derived2 *d2 = dynamic_cast<derived2 *>(b);
    if (d2) {
        d2->print();
    }
    else {
        cout << "d2 is nullptr" << endl;
    }
    //! up casting this is always valid and it will return a pointer to the base class
    std:cout << "\n\n";
    derived1 *d3 = new derived1();
    base *b1 = dynamic_cast<base *>(d3);
    if (b1) {
        b1->print();
    }
    else {
        cout << "b1 is nullptr" << endl;
    }
    return 0;
}