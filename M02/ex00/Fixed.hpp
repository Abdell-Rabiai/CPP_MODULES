# ifndef FIXED_HPP
# define FIXED_HPP 
# include <iostream>
# include <string>

class Fixedpoint
{
    private:
        int _value; //An integer to store the fixed-point number value
        static const int _fractional_bits = 8; // The number of fractional bits
    
    public:
        Fixedpoint(); // A default constructor
        Fixedpoint(const int value); // A constructor that takes a constant integer as a parameter

        Fixedpoint(const Fixedpoint &copy); // A copy constructor
        Fixedpoint &operator=(const Fixedpoint &copy); // An assignation operator overload

        ~Fixedpoint(); // A destructor

        int getRawBits(void) const; // A member function to return the raw value of the fixed point value
        void setRawBits(int const raw); // A member function to set the raw value of the fixed point value
};

# endif // FIXED_HPP# inc