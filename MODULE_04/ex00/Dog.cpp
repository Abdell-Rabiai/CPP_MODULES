# include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    this->type = "Dog"; // this is not necessary
    std::cout << "Dog_default constructor called for " << this->type << std::endl;
}

Dog::Dog(const Dog &rhs)
{
    std::cout << "Dog copy constructor called for " << this->type << std::endl;
    *this = rhs;
}

Dog &Dog::operator=(const Dog &rhs)
{
    std::cout << "Dog assignement operator called" << std::endl;
    this->type = rhs.type;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog_destructor called for " << this->type << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "BARK BARK !!" << std::endl;
}

