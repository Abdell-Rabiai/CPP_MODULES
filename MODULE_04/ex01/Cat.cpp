# include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat_default constructor called" << std::endl;
}

Cat::Cat(const Cat &copy)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = copy;
}

Cat &Cat::operator=(const Cat &copy)
{
    std::cout << "Cat assignement operator called" << std::endl;
    this->type = copy.type;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "MIAOU MIAOU !!" << std::endl;
}
