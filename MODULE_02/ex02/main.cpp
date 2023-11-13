# include "Fixed.hpp"


int main( void ) 
{
    Fixed a;
    // Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed x(5.05f);
    std::cout << "x_ fixed point represenation value : " << x.getRawBits() << std::endl;
    Fixed y(2);
    std::cout << "y_ fixed point represenation value : " << y.getRawBits() << std::endl;
    Fixed z = x * y;
    Fixed const b(z);
    std::cout << "z_ fixed point represenation value : " << z.getRawBits() << std::endl;
    std::cout << "b_ fixed point represenation value : " << b.getRawBits() << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;

    std::cout << "---------------------" << std::endl;

    std::cout <<"a : " << a << std::endl;
    std::cout <<"b : " << b << std::endl;
    std::cout <<"x : " << x << std::endl;
    std::cout <<"y : " << y << std::endl;
    std::cout <<"z : " << z << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    
    return 0;
}
