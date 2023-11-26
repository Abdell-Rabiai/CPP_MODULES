# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"

int main()
{
    // {
    //     const Animal* meta = new Animal(); // this cannot be done anymore since the constructor is protected we cannot create an Animal object directly
    //     delete meta;
    // }
    std::cout << "---------------------" << std::endl;
    {
        const Animal* dog = new Dog();
        delete dog;
    }
    std::cout << "---------------------" << std::endl;
    {
        const Animal* cat = new Cat();
        delete cat;
    }

    return 0;
}