# include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Wrong_Cat")
{
    std::cout << "WrongCat_default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
    std::cout << "WrongCat_type constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &rhs)
{
    std::cout << "WrongCat_copy constructor called" << std::endl;
    *this = rhs;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
    std::cout << "WrongCat_assignation operator called" << std::endl;
    if (this != &rhs)
        this->_type = rhs._type;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat_destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "MEOW MEOW !!!" << std::endl;
}
