# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    std::cout << dog->getType() << " " << std::endl;
    dog->makeSound();
    std::cout << cat->getType() << " " << std::endl;
    cat->makeSound(); // this will output the cat sound!
    meta->makeSound();
    std::cout << std::endl;
    delete meta;
    delete dog;
    delete cat;

    return 0;
}