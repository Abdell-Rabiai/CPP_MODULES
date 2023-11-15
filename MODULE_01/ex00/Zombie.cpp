/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:49:05 by arabiai           #+#    #+#             */
/*   Updated: 2023/11/15 10:08:26 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie::Zombie()
{
    std::cout << "Zombie default constructor called" << std::endl;
    this->name = "default";
    
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
Zombie::Zombie(std::string name) : name(name)
{
    std::cout << "Zombie parameterized constructor called for " << this->name << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie destructor called for " << this->name << std::endl;
}

void Zombie::set_name(std::string name)
{
    this->name = name;
}

std::string Zombie::get_name()
{
    return this->name;
}
