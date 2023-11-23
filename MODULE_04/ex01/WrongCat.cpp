# include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Wrong_Cat")
{
    std::cout << "WrongCat_default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
    std::cout << "WrongCat_type constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
    std::cout << "WrongCat_copy constructor called" << std::endl;
    *this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
    std::cout << "WrongCat_assignation operator called" << std::endl;
    if (this != &copy)
        this->_type = copy._type;
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
