# include "Fixed.hpp"
const int _fractional_bits = 8;

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = value << this->_fractional_bits;
    std::cout << "this->_value : " << this->_value << std::endl;
    // this->_value = value * 256;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(value * (1 << this->_fractional_bits));
    // this->_value = roundf(value * 256);
}

float Fixed::toFloat(void) const
{
    return ((float)this->_value / (1 << this->_fractional_bits));
    // return ((float)this->_value / 256);
}

int Fixed::toInt(void) const
{
    return (this->_value >> this->_fractional_bits);
    // return (this->_value / 256);
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
