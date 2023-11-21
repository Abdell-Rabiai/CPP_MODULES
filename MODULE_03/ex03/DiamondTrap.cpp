/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:03:01 by arabiai           #+#    #+#             */
/*   Updated: 2023/11/21 16:03:01 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
    this->_name = "default_name";
    this->_hitPoints = FragTrap::_hitPoints; // 100
    this->_energyPoints = ScavTrap::_energyPoints; // 50
    this->_attackDamage = FragTrap::_attackDamage; // 30
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name)
{
    std::cout << "DiamondTrap parametrized constructor called" << std::endl;
    this->_name = name;
    this->ClapTrap::_name = name + "_clap_name";
    this->_attackDamage = FragTrap::_attackDamage;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_hitPoints = FragTrap::_hitPoints;
}

DiamondTrap::DiamondTrap(const DiamondTrap& rhs) : ClapTrap(rhs), FragTrap(rhs), ScavTrap(rhs)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = rhs;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& rhs)
{
    std::cout << "DiamondTrap assignement operator called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_attackDamage = rhs._attackDamage;
        this->_energyPoints = rhs._energyPoints;
        this->_hitPoints = rhs._hitPoints;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
    std::cout << "My name is { " << this->_name << " }" << std::endl;
    std::cout << "My ClapTrap::name is { " << ClapTrap::_name << " }" << std::endl;
}

// attack function is inherited from Scavtrap
void	DiamondTrap::attack(std::string const& target)
{
    ScavTrap::attack(target);
}

const std::string&	DiamondTrap::getName(void) const
{
    return (this->_name);
}

const unsigned int&	DiamondTrap::getHitPoints(void) const
{
    return (this->_hitPoints);
}

const unsigned int&	DiamondTrap::getEnergyPoints(void) const
{
    return (this->_energyPoints);
}

const unsigned int&	DiamondTrap::getAttackDamage(void) const
{
    return (this->_attackDamage);
}
