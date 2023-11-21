/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:02:42 by arabiai           #+#    #+#             */
/*   Updated: 2023/11/21 16:02:42 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

int main(void)
{
    FragTrap frag1("frag_X");
    frag1.attack("target");
    frag1.takeDamage( 10 );
    frag1.beRepaired( 10 );

    frag1.highFivesGuys();
    return (0);
}
