# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
int main(void)
{
    ScavTrap    scavTrap("******");
    scavTrap.guardGate();
    scavTrap.attack("$$$$$$");
    scavTrap.takeDamage(5);
    scavTrap.beRepaired(5);
    return (0);
}
