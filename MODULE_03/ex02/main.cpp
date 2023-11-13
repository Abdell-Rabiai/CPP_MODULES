# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

int main(void)
{
    FragTrap frag1("frag1");
    std::cout << "--------" << std::endl;
    FragTrap Frag2(frag1);
    std::cout << "--------" << std::endl;
    frag1.attack("target");
    frag1.takeDamage( 10 );
    frag1.beRepaired( 10 );
    std::cout << "--------" << std::endl;
    frag1.highFivesGuys();
    std::cout << "--------" << std::endl;
    return (0);
}
