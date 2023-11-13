/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:48:43 by arabiai           #+#    #+#             */
/*   Updated: 2023/11/12 20:48:43 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main()
{
    int N = 5;
    Zombie *zombies_array = zombieHorde(N, "zombie");
    if (zombies_array == NULL)
        return 1;
    for (int i = 0; i < N; i++){
        std::cout << "------------------------------------" << std::endl;
        std::cout << "Zombie " << i << " is called \n";
        zombies_array[i].announce();
        std::cout << "------------------------------------" << std::endl;
    }
    delete [] zombies_array;
    return 0;
}