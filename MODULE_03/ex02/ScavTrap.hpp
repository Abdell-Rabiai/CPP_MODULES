#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

# include <iostream>
# include <string>

class ScavTrap : public ClapTrap // ScavTrap publicly inherits from ClapTrap
{
    public :
        // canonical form
        ScavTrap(); // default constructor
        ScavTrap(std::string name); // parameterized constructor
        ScavTrap(const ScavTrap& rhs); // copy constructor
        ScavTrap&	operator=(const ScavTrap& rhs); // copy assignment operator
        ~ScavTrap(); // destructor
        // other member functions
        void    guardGate(); // a function that displays a message when the ScavTrap enters in Gate keeper mode
        void    attack(std::string const& target); // attack function that displays the amount of damage inflicted
};

#endif //SCAVTRAP_HPP