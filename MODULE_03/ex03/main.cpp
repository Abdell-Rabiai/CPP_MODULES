/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:03:14 by arabiai           #+#    #+#             */
/*   Updated: 2023/11/21 16:03:14 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap diamondTrap("DiamondTrap");

    std::cout << diamondTrap.getName() << std::endl;
    std::cout << diamondTrap.getHitPoints() << std::endl;
    std::cout << diamondTrap.getEnergyPoints() << std::endl;
    std::cout << diamondTrap.getAttackDamage() << std::endl;
    diamondTrap.attack("target");
    diamondTrap.whoAmI();

    // diamondTrap.takeDamage(10);
    // diamondTrap.beRepaired(10);
    // diamondTrap.guardGate();
    // diamondTrap.highFivesGuys();
    // diamondTrap.whoAmI();
    std::cout << "-----------" << std::endl;
    return (0);
}
