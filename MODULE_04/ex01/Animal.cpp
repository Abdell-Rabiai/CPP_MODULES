# include "Animal.hpp"

Animal::Animal() : type("7AYAWAN")
{
    std::cout << "Animal_default constructor called" << std::endl;
}

Animal::Animal(std::string type)
{
    std::cout << "Animal parametrized constructor called" << std::endl;
    this->type = type;
}

Animal::Animal(const Animal &copy)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = copy;
}

Animal &Animal::operator=(const Animal &copy)
{
    std::cout << "Animal assignement operator called" << std::endl;
    this->type = copy.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return (this->type);
}

void Animal::makeSound() const
{
    std::cout << "Animal makeSound called" << std::endl;
}

void Animal::setType(std::string type)
{
    this->type = type;
}