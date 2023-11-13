# ifndef FIXED_HPP
# define FIXED_HPP 
# include <iostream>
# include <string>

class Fixed
{
    private:
        int _value; //An integer to store the fixed-point number value
        static const int _fractional_bits; // The number of fractional bits
    
    public:
        Fixed(); // A default constructor
        Fixed(const int value); // A constructor that takes a constant integer as a parameter

        Fixed(const Fixed &copy); // A copy constructor
        Fixed &operator=(const Fixed &copy); // An assignation operator overload

        ~Fixed(); // A destructor

        int getRawBits(void) const; // A member function to return the raw value of the fixed point value
        void setRawBits(int const raw); // A member function to set the raw value of the fixed point value
};

# endif // FIXED_HPP