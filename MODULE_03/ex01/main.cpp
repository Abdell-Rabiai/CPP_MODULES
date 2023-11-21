# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
int main(void)
{
    ScavTrap scavTrap("A");
    scavTrap.guardGate();
    scavTrap.attack("B");
    scavTrap.takeDamage(5);
    scavTrap.beRepaired(5);
    return (0);
}
