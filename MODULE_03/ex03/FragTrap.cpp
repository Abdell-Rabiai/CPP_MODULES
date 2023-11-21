# include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    // not necessary
    // this->_hitPoints = 100;
    // this->_energyPoints = 100;
    // this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap parameter constructor called" << std::endl;
    // not necessary, they've been already initialized in the ClapTrap constructor
    // this->_hitPoints = 100;
    // this->_energyPoints = 100;
    // this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& rhs) : ClapTrap(rhs)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = rhs;
}

FragTrap&	FragTrap::operator=(const FragTrap& rhs)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_hitPoints = rhs._hitPoints;
        this->_energyPoints = rhs._energyPoints;
        this->_attackDamage = rhs._attackDamage;
    }
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
    std::cout << "{ FragTrap " << this->_name << " asks for a high five }" << std::endl;
}