# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("GENERIC_WRONG_ANIMAL")
{
    std::cout << "WrongAnimal_default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
    std::cout << "WrongAnimal_parametrized constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &rhs)
{
    std::cout << "WrongAnimal_copy constructor called" << std::endl;
    *this = rhs;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
    std::cout << "WrongAnimal_assignement operator called" << std::endl;
    if (this != &rhs)
        this->_type = rhs._type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal_destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->_type);
}

void WrongAnimal::makeSound() const
{
    std::cout << "WRONG ANIMAL SOOUND !!!" << std::endl;
}