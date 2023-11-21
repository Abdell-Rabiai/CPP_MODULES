# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"

void lk(void){ system("leaks ex01"); }

int main()
{
    atexit (lk);
    // const Animal* dog = new Dog();
    // const Animal* cat = new Cat();
    // std::cout << std::endl;

    // delete dog;
    // delete cat;

    const int size = 4; // 8 animals (half will be dogs and half will be cats)
    Animal animals[size];
    std::cout << "----------------------------------------" << std::endl;
    for (int i = 0; i < size / 2; ++i) // fill the first half with dogs
        animals[0] = Dog();
    std::cout << "----------------------------------------" << std::endl;
    for (int i = size / 2; i < size; ++i) // fill the second half with cats
        animals[i] =  Cat();
    std::cout << "----------------------------------------" << std::endl;
    // for (int i = 0; i < size; ++i) // make all the animals makeSound
    //     animals[i]->makeSound();
    
    // for (int i = 0; i < size; ++i) // delete all the animals
    //     delete animals[i]; // the destructor of the derived class will be called first and then the destructor of the base class will be called
    // and the appropriate destructors will be called because the destructor of the base class is virtual
    // if the destructor of the base class was not virtual, the destructor of the derived class will not be called
    // causing memory leaks

    // std::cin.get();
    return 0;
}