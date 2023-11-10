# include "Fixed.hpp"
#define RED "\001\033[1;32m\002"
#define END "\001\033[0m\002\n"
int main()
{
    std::cout <<RED<<"creating the instance a"<<END<< std::endl;
    Fixed a;
    std::cout <<RED<<"creating the instance b as a copy of a "<<END<<std::endl;
    Fixed b(a);
    std::cout <<RED<<"creating the instance c for which we assign b "<<END<<std::endl;
    Fixed c;
    c = b;
    std::cout << std::endl;
    std::cout <<RED<<"dispalying the values: the getRawBits functions"<<END<<std::endl;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    std::cout <<RED<<"calling the destructers "<<END<<std::endl;

    return 0;
}