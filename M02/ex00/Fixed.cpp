# include "Fixed.hpp"

Fixedpoint::Fixedpoint() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
    this->_value = 0;
}

Fixedpoint::Fixedpoint(const int value)
{
    std::cout << "parametrized Int constructor called" << std::endl;
    this->_value = value;
}

Fixedpoint::Fixedpoint(const Fixedpoint &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixedpoint &Fixedpoint::operator=(const Fixedpoint &copy)
{
    std::cout << "Assignation operator called" << std::endl;
    this->_value = copy.getRawBits();
    return *this;
}

Fixedpoint::~Fixedpoint()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixedpoint::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

void Fixedpoint::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}
