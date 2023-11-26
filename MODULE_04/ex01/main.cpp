# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"

int main()
{
    const int size = 4; // 8 animals (half will be dogs and half will be cats)
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    std::cout << std::endl;

    delete dog;
    delete cat;


    // /*test using an array of Animal objects*/
    // Animal animals[size];
    // std::cout << "----------------------------------------" << std::endl;
    // for (int i = 0; i < size / 2; ++i) // fill the first half with dogs
    //     animals[0] = Dog();
    // std::cout << "----------------------------------------" << std::endl;
    // for (int i = size / 2; i < size; ++i) // fill the second half with cats
    //     animals[i] =  Cat();
    // std::cout << "----------------------------------------" << std::endl;
    // for (int i = 0; i < size; ++i) // make all the animals makeSound
    //     animals[i].makeSound();
    // /*test using an array of Animal pointers*/
    // std::cout << "----------------------------------------" << std::endl;

    Animal *animals2[size];
    for (int i = 0; i < size; ++i) // fill the array with dogs and cats
    {
        if (i % 2 == 0)
            animals2[i] = new Dog();
        else
            animals2[i] = new Cat();
    }
    std::cout << "----------------------------------------" << std::endl;
    for (int i = 0; i < size; ++i) // make all the animals makeSound
    {
        std::cout << "Animal " << i << " : of type " << animals2[i]->getType() << " says ";
        animals2[i]->makeSound();
    }
    std::cout << "----------------------------------------" << std::endl;
    for (int i = 0; i < size; ++i) // delete all the animals
        delete animals2[i];
    return 0;
}