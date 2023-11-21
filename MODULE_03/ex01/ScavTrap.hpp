#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

# include <iostream>
# include <string>

class ScavTrap : public ClapTrap 
{
    public :
        
        ScavTrap(); 
        ScavTrap(std::string name); 
        ScavTrap(const ScavTrap& rhs); 
        ScavTrap&	operator=(const ScavTrap& rhs); 
        ~ScavTrap(); 
        
        void    guardGate(); 
        void    attack(std::string const& target); 
};

#endif //SCAVTRAP_HPP