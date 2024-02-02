#include <iostream>
#include <stdexcept>
#include <iomanip>

class Base {
    public:
        Base() {};
        int x = {42};
         ~Base() {};
        virtual void print() {
            std::cout << "Base::print " << x << std::endl;
        }
};

class Derived : public Base {
    public:
        Derived() {};
        int y = {1337};
        // copy constructor
        // Derived(const Base &b) {
        //     x = b.x;
        // }
         ~Derived() {};
        virtual void print() override {
            std::cout << "Derived::print " << y << std::endl;
        }
};

class Unrelated {
    public:
        Unrelated() {};
        int z = {69};
         ~Unrelated() {};
        void print() {
            std::cout << "Unrelated::print " << z << std::endl;
        }
};

int main() {

        // int *p = new int(42);
        // char *charp = reinterpret_cast<char *>(p);
        // // same as
        // // int *p1 = new int(42);
        // // char *charp = (char *)p1;
        // std::cout << *p << std::endl;
        // std::cout << *charp << std::endl;

        // Derived d;
        // Base b;

        // d.print();
        // b.print();
        // static_cast -------------------------------->
        // // treat a pointer to a derived class as a pointer to a base class: treat d as a base
        // Base d2 = static_cast<Base>(d); // d2 is a copy of d (slicing) : SLICING IS THE PROCESS OF COPYING THE BASE PART OF A DERIVED OBJECT INTO A NEW BASE OBJECT 
        // d2.print();

        // treat a pointer to a base class as a pointer to a derived class: treat b as a derived
        // Derived d3;
        // d3 = static_cast<Derived>(b);
        // d3.print();

        // Base *b = new Base();
        // Derived *d = new Derived();
        // // try with virtual functions and without
        // d->print();
        // static_cast<Derived *>(b)->print();

        // dynamic_cast -------------------------------->
        // Base *b = new Base();
        // Derived *d = new Derived();
        // // try with virtual functions and without
        // d->print();
        // // dynamic_cast<Derived *>(b)->print(); // this is not valid, it returns a nullptr

        // // dynamic_cast<Base *>(d)->print(); // this is valid but it doesnt change the type of d to Base, it just returns a pointer to a Base object that is a copy of d

        // Derived *d = new Derived();
        // static_cast<Base *>(d)->print();
        // static_cast<Unrelated *>(d)->print(); // not allowed because they are not related in any way (no inheritance)
        // // but using dynamic_cast it compiles but it returns a nullptr
        // // dynamic_cast<Unrelated *>(d)->print(); // this is not valid, it returns a nullptr
        // // but using reinterpret_cast it compiles but it returns a garbage value
        // // reinterpret_cast<Unrelated *>(d)->print(); // this is possible because reinterpret_cast is a C-style cast, it just changes the type of the pointer, it doesnt check if the types are related in any way


    return 0;
}
