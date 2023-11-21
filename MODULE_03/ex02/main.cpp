# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

int main(void)
{
    FragTrap frag1("frag_1");
    frag1.attack("target");
    frag1.takeDamage( 10 );
    frag1.beRepaired( 10 );

    frag1.highFivesGuys();
    return (0);
}
