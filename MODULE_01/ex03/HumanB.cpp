/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:48:26 by arabiai           #+#    #+#             */
/*   Updated: 2024/01/19 21:53:43 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanB.hpp"

HumanB::HumanB() : name("default"), weapon(NULL)
{
    std::cout << "HumanB default constructor called for " << this->name << std::endl;
}

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
    std::cout << "HumanB parameterized constructor called for " << this->name << std::endl;
}

HumanB::~HumanB()
{
    std::cout << "HumanB destructor~ called for " << this->name << std::endl;
}

void HumanB::attack()
{
    if (this->weapon != NULL)
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
