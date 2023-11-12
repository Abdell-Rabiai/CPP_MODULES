/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:48:16 by arabiai           #+#    #+#             */
/*   Updated: 2023/11/12 20:48:16 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include  "Weapon.hpp"

Weapon::Weapon() : type("default")
{
    std::cout << "Weapon default constructor called" << std::endl;
}

Weapon::Weapon(std::string type) : type(type)
{
    std::cout << "Weapon parameterized constructor called" << std::endl;
}

Weapon::~Weapon()
{
    std::cout << "Weapon destructor called" << std::endl;
}

std::string Weapon::get_type()
{
    return (this->type);
}

void Weapon::set_type(std::string type)
{
    this->type = type;
}

