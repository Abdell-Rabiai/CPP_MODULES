# include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    this->type = "Cat"; // this is not necessary
    std::cout << "Cat_default constructor called" << std::endl;
}

Cat::Cat(const Cat &copy)
{
    std::cout << "Cat_copy constructor called" << std::endl;
    *this = copy;
}

Cat &Cat::operator=(const Cat &copy)
{
    std::cout << "Cat_assignement operator called" << std::endl;
    this->type = copy.type;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat_destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "MIAOU MIAOU !!" << std::endl;
}
