/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:48:56 by arabiai           #+#    #+#             */
/*   Updated: 2023/11/14 19:11:10 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main()
{

    randomChump("Stack_Zombie");

    std::cout << "\n------------------------------------------------------\n" << std::endl;

    Zombie *zombie2 = newZombie("Heap_Zombie");
    zombie2->announce();


    std::cout << "\n-------------------Destructors----------------->\n" << std::endl;
    delete zombie2;
    return 0;
}