# include <iostream>
# include <string>

class Base
{
    public :
        Base() {
            std::cout << "base constructor called" << std::endl;
        }
        ~Base() {
            std::cout << "base destructor called" << std::endl;
        }
        void method() {
            std::cout << "base method called" << std::endl;
        }
};

class Derived : public Base
{
    public :
        Derived() {
            std::cout << "derived constructor called" << std::endl;
        }
        ~Derived() {
            std::cout << "derived destructor called" << std::endl;
        }
        void method() {
            std::cout << "derived method called" << std::endl;
        }
};

int main(void)
{

    return 0;
}