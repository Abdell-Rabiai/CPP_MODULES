# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("GENERIC_WRONG_ANIMAL")
{
    std::cout << "WrongAnimal_default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
    std::cout << "WrongAnimal_type constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    std::cout << "WrongAnimal_copy constructor called" << std::endl;
    *this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
    std::cout << "WrongAnimal_assignation operator called" << std::endl;
    if (this != &copy)
        this->_type = copy._type;
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