/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:03:22 by arabiai           #+#    #+#             */
/*   Updated: 2023/11/21 16:03:22 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

# include <iostream>
# include <string>

class ScavTrap : virtual public ClapTrap
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