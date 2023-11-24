# include "Animal.hpp"

Animal::Animal() : type("GENERIC_ANIMAL")
{
    std::cout << "Animal_default constructor called" << std::endl;
}

Animal::Animal(std::string type)
{
    std::cout << "Animal_parametrized constructor called" << std::endl;
    this->type = type;
}

Animal::Animal(const Animal &copy)
{
    std::cout << "Animal_copy constructor called" << std::endl;
    *this = copy;
}

Animal &Animal::operator=(const Animal &copy)
{
    std::cout << "Animal_assignement operator called" << std::endl;
    this->type = copy.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal_destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return (this->type);
}

// void Animal::makeSound() const
// {
//     std::cout << "Generic Animal Sound !!!" << std::endl;
// }

void Animal::setType(std::string type)
{
    this->type = type;
}