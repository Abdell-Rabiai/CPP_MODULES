/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:02:59 by arabiai           #+#    #+#             */
/*   Updated: 2023/11/21 16:02:59 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
    protected :
        std::string		_name; 
        unsigned int	_hitPoints; 
        unsigned int	_energyPoints; 
        unsigned int	_attackDamage;

    public :
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& rhs);
        ClapTrap&	operator=(const ClapTrap& rhs);
        ~ClapTrap();
    
        void		attack(std::string const& target);
        void		takeDamage(unsigned int amount);
        void		beRepaired(unsigned int amount);
    
        const std::string	&getName() const;
        unsigned int	getHitPoints() const;
        unsigned int	getEnergyPoints() const;
        unsigned int	getAttackDamage() const;
    
        void	setName(std::string name);
        void	setHitPoints(unsigned int hitPoints);
        void	setEnergyPoints(unsigned int energyPoints);
        void	setAttackDamage(unsigned int attackDamage);
};

# endif //CLAPTRAP_HPP