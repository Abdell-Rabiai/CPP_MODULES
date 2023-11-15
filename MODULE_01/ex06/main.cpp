/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:48:05 by arabiai           #+#    #+#             */
/*   Updated: 2023/11/15 11:15:11 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

int main(void)
{
    Harl harl;
    std::cout << "Please enter a level of complain (debug, info, warning, error): \n";
    while (true)
    {
        std::cout << ">> ";
        std::string level;
        std::cin >> level;
        if (level == "EXIT" || std::cin.eof()){
            std::cin.clear();
            std::cout << "Exiting ...!" << std::endl;
            exit(0) ;
        }
        harl.complain(level);
    }
}