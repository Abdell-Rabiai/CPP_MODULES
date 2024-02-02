/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:48:34 by arabiai           #+#    #+#             */
/*   Updated: 2024/01/19 21:53:55 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
    std::cout << "HumanA parameterized constructor called" << std::endl;
}

HumanA::~HumanA()
{
    std::cout << "HumanA destructor called for " << this->name << std::endl;
}

void HumanA::attack()
{
    std::cout << this->name << " attacks with his " << this->weapon.get_type() << std::endl;
}

std::string HumanA::get_name() const
{
    return (this->name);
}
