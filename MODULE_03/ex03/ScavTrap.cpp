/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:03:20 by arabiai           #+#    #+#             */
/*   Updated: 2023/11/21 16:03:20 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("default_name")
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap parametrized constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& rhs)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = rhs;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& rhs)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_hitPoints = rhs._hitPoints;
        this->_energyPoints = rhs._energyPoints;
        this->_attackDamage = rhs._attackDamage;
    }
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::guardGate()
{
    std::cout << "{ ScavTrap " << this->_name << " has entered the GATE KEEPER MODE }" << std::endl;
}

void	ScavTrap::attack(std::string const& target)
{
    if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
    {
        std::cout << "{ ScavTrap " << this->_name << " has no energy points left to attack with! }" << std::endl;
        return ;
    }
    std::cout << "{ ScavTrap " << this->_name << " attacks " << target <<
        " causing " << this->_attackDamage << " points of damage! }" << std::endl;
    this->_energyPoints -= 1;
}