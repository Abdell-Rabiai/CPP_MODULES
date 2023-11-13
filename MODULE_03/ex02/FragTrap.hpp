#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

# include <iostream>
# include <string>

class FragTrap : public ClapTrap
{
    public :
        // canonical form
        FragTrap(); // default constructor
        FragTrap(std::string name); // parameter constructor
        FragTrap(const FragTrap& rhs); // copy constructor
        FragTrap&	operator=(const FragTrap& rhs); // copy assignment operator
        ~FragTrap(); // destructor
        // other member functions
        void		highFivesGuys(void); // ask for a high five
};

#endif //FRAGTRAP_HPP