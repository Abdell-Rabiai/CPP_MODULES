# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap diamondTrap("DiamondTrap");

    diamondTrap.attack("target");
    diamondTrap.takeDamage(10);
    diamondTrap.beRepaired(10);
    diamondTrap.guardGate();
    diamondTrap.highFivesGuys();
    diamondTrap.whoAmI();
    return (0);
}
