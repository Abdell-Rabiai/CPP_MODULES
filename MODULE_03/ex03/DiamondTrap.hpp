/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:03:03 by arabiai           #+#    #+#             */
/*   Updated: 2023/11/21 16:03:04 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

# include <iostream>
# include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string _name;

    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& rhs);
        DiamondTrap&	operator=(const DiamondTrap& rhs);
        ~DiamondTrap();

        void	whoAmI(void);
        void	attack(std::string const& target);

        const std::string&	getName(void) const;
        const unsigned int&	getHitPoints(void) const;
        const unsigned int&	getEnergyPoints(void) const;
        const unsigned int&	getAttackDamage(void) const;
};
#endif //DIAMONDTRAP_HPP