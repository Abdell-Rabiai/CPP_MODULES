# include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    this->type = "Cat"; // this is not necessary because the base class constructor already initialized this->type
    std::cout << "Cat_default constructor called for " << this->type << std::endl;
}

Cat::Cat(const Cat &rhs)
{
    std::cout << "Cat_copy constructor called for " << this->type << std::endl;
    *this = rhs;
}

Cat &Cat::operator=(const Cat &rhs)
{
    std::cout << "Cat_assignement operator called" << std::endl;
    if (this != &rhs)
        this->type = rhs.type;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat_destructor called for " << this->type << std::endl;
}

// this is the function that is called when we call makeSound() on a Cat object
// it is the overriden version of the makeSound() function in the base class Animal
// theu have the same signature (return type, name, and parameters) but different implementations
// depending on the type of the object that calls it and this is what polymorphism based on inheritance is all about
void Cat::makeSound() const
{
    std::cout << "MIAOU MIAOU !!" << std::endl;
}
