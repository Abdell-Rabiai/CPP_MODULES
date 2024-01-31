#include <iostream>
#include <stdexcept>
#include <iomanip>

class Base {
    public:
        virtual ~Base() {};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};


int main() {

        // int *p = new int(42);
        // char *charp = static_cast<char *>(p);

        int *p1 = new int(42);
        char *charp = (char *)p1;

    return 0;
}
