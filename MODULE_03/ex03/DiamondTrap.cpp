# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name.append("_clap_name")), FragTrap(name), ScavTrap(name), _name(name)
{
    FragTrap::_hitPoints = 100;
    ScavTrap::_energyPoints = 50;
    FragTrap::_attackDamage = 30;
    std::cout << "DiamondTrap " << this->_name << " is CONSTRUCTED!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->_name << " is DESTROYED!" << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap " << this->_name << " is " << this->ClapTrap::_name << std::endl;
}
