# include "Fixed.hpp"
#define RED "\001\033[1;32m\002"
#define END "\001\033[0m\002\n"
int main()
{
    Fixed a;
    Fixed b( a );
    Fixed c;
    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}