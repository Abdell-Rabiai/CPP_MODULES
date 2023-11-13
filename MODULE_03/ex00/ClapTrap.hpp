#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
    protected:
        std::string		_name; // the name of the ClapTrap
        unsigned int	_hitPoints; // the ammount of damage a ClapTrap can take before it dies
        unsigned int	_energyPoints; // the ammount of energy a ClapTrap has available
        unsigned int	_attackDamage;  // the ammount of damage a ClapTrap can inflict on another ClapTrap
    public:
        // canonical form
        ClapTrap(); // default constructor
        ClapTrap(std::string name); // parameter constructor
        ClapTrap(const ClapTrap& rhs); // copy constructor
        ClapTrap&	operator=(const ClapTrap& rhs); // copy assignment operator
        ~ClapTrap(); // destructor
        // other member functions
        void		attack(std::string const& target); // attack function that displays the amount of damage inflicted
        void		takeDamage(unsigned int amount); // take damage function that displays the amount of damage taken
        void		beRepaired(unsigned int amount); // repair function that displays the amount of health restored
        // getters
        std::string	getName() const;
        unsigned int	getHitPoints() const;
        unsigned int	getEnergyPoints() const;
        unsigned int	getAttackDamage() const;
        // setters
        void	setName(std::string name);
        void	setHitPoints(unsigned int hitPoints);
        void	setEnergyPoints(unsigned int energyPoints);
        void	setAttackDamage(unsigned int attackDamage);
};

# endif //CLAPTRAP_HPP