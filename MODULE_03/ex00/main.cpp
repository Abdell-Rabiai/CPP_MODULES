# include "ClapTrap.hpp"

int main(void)
{
    std::cout << "Welcome to the Claptrap useless game\n" << std::endl;
    ClapTrap A("A");
    ClapTrap B("B");
    ClapTrap ACopy(B); // here just to show that the copy constructor works

    A.attack("B");
    A.takeDamage(5);
    A.takeDamage(5);
    A.takeDamage(5);
    A.beRepaired(5);
    A.beRepaired(5);
    A.attack("B");
    std::cout << "---------------------" << std::endl;
    ACopy.attack("TARGET_NAME");
    ACopy.takeDamage(5);
    ACopy.beRepaired(5);
    std::cout << "---------------------" << std::endl;
    return (0);
}