# include "Animal.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"
# include "Dog.hpp"
# include "Cat.hpp"

int main()
{
    {
        const Animal* meta = new Animal();
        const Animal* dog = new Dog();
        const Animal* cat = new Cat();
        std::cout << "--------------------DOG-------------------------" << std::endl;
        std::cout << dog->getType() << " " << std::endl;
        dog->makeSound();
        std::cout << "--------------------CAT-------------------------" << std::endl;
        std::cout << cat->getType() << " " << std::endl;
        cat->makeSound(); // this will output the cat sound!
        std::cout << "--------------------GENERIC-------------------------" << std::endl;
        meta->makeSound();
        std::cout << std::endl;
        delete meta;
        delete dog;
        delete cat;
    }
    std::cout << "\n*****************************************************************\n" << std::endl;

    {
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* cat = new WrongCat();
        std::cout << "--------------------CAT-------------------------" << std::endl;
        std::cout << cat->getType() << " " << std::endl;
        cat->makeSound(); // this will output the cat sound!
        std::cout << "--------------------GENERIC-------------------------" << std::endl;
        meta->makeSound();
        std::cout << std::endl;
        delete meta;
        delete cat;
    }
    return 0;
}