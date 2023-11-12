/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:48:26 by arabiai           #+#    #+#             */
/*   Updated: 2023/11/12 20:48:26 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanB.hpp"

HumanB::HumanB()
{
    std::cout << "HumanB default constructor called" << std::endl;
}

HumanB::HumanB(std::string name) : name(name)
{
    std::cout << "HumanB parameterized constructor called" << std::endl;
}

HumanB::~HumanB()
{
    std::cout << "HumanB destructor called" << std::endl;
}

void HumanB::attack()
{
    std::cout << this->name << " attacks with his " << this->weapon->get_type() << std::endl;
}

void HumanB::set_weapon(Weapon *weapon)
{
    this->weapon = weapon;
}

std::string HumanB::get_name() const
{
    return (this->name);
}
