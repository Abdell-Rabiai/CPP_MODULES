/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:48:10 by arabiai           #+#    #+#             */
/*   Updated: 2023/11/15 11:28:20 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void Harl::debug(void)
{
    std::cout << "\n[ DEBUG ]I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << std::endl;
}

void Harl::info(void)
{
    std::cout << "\n[ INFO ] : I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!\n" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "\n[ WARNING ] : I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month.\n" << std::endl;
}

void Harl::error(void)
{
    std::cout << "\n[ ERROR ] : This is unacceptable, I want to speak to the manager now.\n" << std::endl;
}

void Harl::invalid(void)
{
    std::cout << "\n[ Probably complaining about insignificant problems! ]\n" << std::endl;
}

unsigned int customHash(const std::string& input) {
    unsigned int hash = 0;

    for (size_t i = 0; i < input.length(); i++) {
        hash = (hash * 7) + (unsigned int)(input[i]);
    }
    return hash;
}

void Harl::complain( std::string level )
{
    unsigned int hashed_level = customHash(level);
    switch (hashed_level)
    {
        case 190835:
            Harl::debug();
        case 29430:
            Harl::info();
        case 11555748:
            Harl::warning();
        case 198448:
            Harl::error();
            break ;
        default:
            Harl::invalid();
    }
}
