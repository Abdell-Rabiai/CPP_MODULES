# include "Fixed.hpp"
const int Fixed::_fractional_bits = 8;

Fixed::Fixed()
{
    // std::cout << "Default constructor called" << std::endl;
    this->_value = 0;
}

Fixed::Fixed(const int value)
{
    // std::cout << "Int constructor called" << std::endl;
    this->_value = value << this->_fractional_bits;
    // this->_value = value * 256;
}

int Fixed::toInt(void) const
{
    // return (this->_value / 256);
    return (this->_value >> this->_fractional_bits);
}

Fixed::Fixed(const float value)
{
    // std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(value * (1 << this->_fractional_bits));
    // this->_value = roundf(value * 256);
}

float Fixed::toFloat(void) const
{
    // return ((float)this->_value / 256);
    return ((float)this->_value / (1 << this->_fractional_bits));
}


std::ostream &operator<<(std::ostream &out, const Fixed &rh)
{
    out << rh.toFloat();
    return out;
}

Fixed::Fixed(const Fixed &copy)
{
    // std::cout << "Copy constructor called" << std::endl;
    // this->_value = copy.getRawBits();
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    this->_value = copy.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}

// Comparison operators overload
bool Fixed::operator>(const Fixed &rhs) const
{
    return (this->_value > rhs._value);
}

bool Fixed::operator<(const Fixed &rhs) const
{
    return (this->_value < rhs._value);
}

bool Fixed::operator>=(const Fixed &rhs) const
{
    return (this->_value >= rhs._value);
}

bool Fixed::operator<=(const Fixed &rhs) const
{
    return (this->_value <= rhs._value);
}

bool Fixed::operator==(const Fixed &rhs) const
{
    return (this->_value == rhs._value);
}

bool Fixed::operator!=(const Fixed &rhs) const
{
    return (this->_value != rhs._value);
}

// Arithmetic operators overload

Fixed Fixed::operator+(const Fixed &rhs) const
{
    Fixed result;

    result._value = this->_value + rhs._value;
    return (result);
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
    Fixed result;

    result._value = this->_value - rhs._value;
    return (result);
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
    Fixed result;
    
    result._value = (this->_value * rhs._value) >> this->_fractional_bits ;
    return (result);
    // return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
    Fixed result;
    if (rhs._value == 0)
    {
        std::cout << "Error: division by zero" << std::endl;
        result._value = 0;
        return (result);
    }
    result._value = (this->_value << this->_fractional_bits / rhs._value);
    return (result);
}

// Increment and decrement operators overload

Fixed &Fixed::operator++() // Pre-increment
{
    ++this->_value;
    return (*this);
}

Fixed Fixed::operator++(int) // Post-increment
{
    Fixed result(*this);

    this->_value++;
    return (result);
}

Fixed &Fixed::operator--() // Pre-decrement
{
    this->_value--;
    return (*this);
}

Fixed Fixed::operator--(int) // Post-decrement
{
    Fixed result(*this);

    this->_value--;
    return (result);
}

// Min and max functions

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    std::cout << "simple\n";
    return (a > b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    std::cout << "const\n";
    return (a > b ? a : b);
}