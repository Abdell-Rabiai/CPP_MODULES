#include <string_view>
# include <iostream>
# include <string>

class Base
{
    protected:
        int m_value;

    public:
        Base(int value) : m_value(value) {
        }

        std::string_view getName() const { return "Base"; }
        int getValue() const { return m_value; }
};

class Derived: public Base
{
    public:
        Derived(int value) : Base(value) {
        }   

    std::string_view getName() const { return "Derived"; }
    int getValueDoubled() const { return m_value * 2; }
};

int main()
{
    Derived derived(5);
    Base &rbase(derived);
    Base *pbase(&derived);

    std::cout << "derived is a {" << derived.getName() << "} and has value {" << derived.getValue() << "}\n";
    std::cout << "rbase is a {" << rbase.getName() << "} and has value {" << rbase.getValue() << "}\n";
    std::cout << "pbase is a {" << pbase->getName() << "} and has value {" << pbase->getValue() << "}\n";
    // note that pbase and rbase don't have access to getValueDoubled() and Derived::getName() or anything else that's specific to Derived
    // so base pointers/references can only access the base class portion of an object even if the object is actually a derived class object
    /*
    Derived::getName() shadows (hides) Base::getName() for Derived objects, the Base pointer/reference can not see Derived::getName()*/
    return 0;
}