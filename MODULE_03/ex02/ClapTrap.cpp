# include "ClapTrap.hpp"

// default constructor
ClapTrap::ClapTrap() : _name("default_name"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

// parameter constructor
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap parametrized constructor called" << std::endl;
}

// copy constructor
ClapTrap::ClapTrap(const ClapTrap& rhs)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = rhs;
}

// copy assignment operator
ClapTrap&	ClapTrap::operator=(const ClapTrap& rhs)
{
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_hitPoints = rhs._hitPoints;
        this->_energyPoints = rhs._energyPoints;
        this->_attackDamage = rhs._attackDamage;
    }
    return (*this);
}

// destructor
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

// other member functions
void	ClapTrap::attack(std::string const& target)
{
    if (this->_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " has no energy points left to attack with!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " attacks " << target <<
        " causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " is DEAD, he has no hit points left to take damage with!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " takes " << amount <<
        " points of damage!" << std::endl;
    this->_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " has no energy points left to be repaired with!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " is repaired gaining " << amount <<
        " points of health!" << std::endl;
    this->_hitPoints += amount;
    this->_energyPoints -= 1;
}

// getters
std::string	ClapTrap::getName() const
{
    return (this->_name);
}

unsigned int	ClapTrap::getHitPoints() const
{
    return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints() const
{
    return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage() const
{
    return (this->_attackDamage);
}

// setters

void	ClapTrap::setName(std::string name)
{
    this->_name = name;
}

void	ClapTrap::setHitPoints(unsigned int hitPoints)
{
    this->_hitPoints = hitPoints;
}

void	ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
    this->_energyPoints = energyPoints;
}

void	ClapTrap::setAttackDamage(unsigned int attackDamage)
{
    this->_attackDamage = attackDamage;
}
