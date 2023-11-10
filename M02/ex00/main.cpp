# include "Fixed.hpp"

int main()
{
    std::cout << "\n<---creating the instance a --->\n" << std::endl;
    Fixedpoint a;
    std::cout << "\n<---creating the instance b as a copy of a --->\n" << std::endl;
    Fixedpoint b(a);
    std::cout << "\n<---creating the instance c for which we assign b --->\n" << std::endl;
    Fixedpoint c;
    c = b;
    std::cout << std::endl;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    std::cout << "\n<---calling the destructers --->\n" << std::endl;

    return 0;
}