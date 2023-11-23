# include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    this->type = "Dog"; // this is not necessary
    std::cout << "Dog_default constructor called" << std::endl;
}

Dog::Dog(const Dog &copy)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = copy;
}

Dog &Dog::operator=(const Dog &copy)
{
    std::cout << "Dog assignement operator called" << std::endl;
    this->type = copy.type;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog_destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "BARK BARK !!" << std::endl;
}

