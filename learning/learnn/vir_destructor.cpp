# include <iostream>
# include <string>

/*****************Virtual Destructor*****************/
class Base
{
    public :
        Base() {
            std::cout << "base constructor called" << std::endl;
            baseData = new int[10];
        }
        virtual ~Base() {
            std::cout << "base destructor called" << std::endl;
            delete [] baseData;
        }
        void method() {
            std::cout << "base method called" << std::endl;
        }
    int  *baseData;
};

class Derived : public Base
{
    public :
        Derived() {
            std::cout << "derived constructor called" << std::endl;
            derivedData = new int[10];
        }
        ~Derived() {
            std::cout << "derived destructor called" << std::endl;
            delete [] derivedData;
        }
        void method() {
            std::cout << "derived method called" << std::endl;
        }
    int *derivedData;
    
};

int main(void)
{
    // we create a base class pointer base* taht can point to a base class object or a derived class object,
    // ei anythign that is derived from base
    // we also have a vtbl that is created for this instance of the object which is in this case Derived
    Base *instance = new Derived();
    // when we call the metho, the vtable points us to the correct method to call (derived method)
    instance->method();
    delete instance;

    // here we change the instance to a base class pointer that points to a base class object
    instance = new Base();
    // when we call the method, the vtable pointer gets updated to point to the base class method
    instance->method();
    // when we delete the instance, the base class destructor is called
    delete instance;

    std::cin.get();
    return 0;
}

// making our base class destructor virtual essentially tells the compiler of c++ instead of just calling the base class destructor,
// look further down the inheritance chain see what the actual type of the object is and then call the derived class destructor of that type.