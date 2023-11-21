/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:02:15 by arabiai           #+#    #+#             */
/*   Updated: 2023/11/21 16:02:15 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
int main(void)
{
    ScavTrap scavTrap("A");
    scavTrap.guardGate();
    scavTrap.attack("B");
    scavTrap.takeDamage(5);
    scavTrap.beRepaired(5);
    return (0);
}
