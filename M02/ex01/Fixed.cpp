# include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
    this->_value = 0;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = value * 256;
    // Or this->_value = value << this->_fractional_bits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(value * 256);
    // Or this->_value = roundf(value * (1 << this->_fractional_bits));
}

float Fixed::toFloat(void) const
{
    return ((float)this->_value / 256);
    // Or return ((float)this->_value / (1 << this->_fractional_bits));
}

int Fixed::toInt(void) const
{
    return (this->_value / 256);
    // return (this->_value >> this->_fractional_bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    // this->_value = copy.getRawBits();
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    // this->_value = copy.getRawBits();
    this->_value = copy._value;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}
