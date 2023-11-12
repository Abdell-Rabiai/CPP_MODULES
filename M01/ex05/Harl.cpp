/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:48:10 by arabiai           #+#    #+#             */
/*   Updated: 2023/11/12 20:48:10 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

Harl::Harl(void)
{
    // std::cout << "Harl constructor called" << std::endl;
}

Harl::~Harl(void)
{
    // std::cout << "Harl destructor called" << std::endl;
}

void Harl::debug(void)
{
    std::cout << "\nDEBUG : I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n\n" << std::endl;
}

void Harl::info(void)
{
    std::cout << "\nINFO : I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!\n" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "\nWARNING : I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month.\n" << std::endl;
}

void Harl::error(void)
{
    std::cout << "\nERROR : This is unacceptable, I want to speak to the manager now.\n" << std::endl;
}

void Harl::invalid(void)
{
    std::cout << "\nINVALID input, Wrong level of complain!\n" << std::endl;
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
    // void (X::* ptfptr) (int) = &X::f; X is the class name
    void (Harl::* my_pointer) (void) = nullptr;   // declare a pointer to a member function void debug (void);
    unsigned int hashed_level = customHash(level);
    std::cout << customHash(level);
    switch (hashed_level)
    {
    case 190835:
        my_pointer = &Harl::debug;
        break;
    case 29430:
        my_pointer = &Harl::info;
        break ;
    case 198448:
        my_pointer = &Harl::error;
        break ;
    case 11555748:
        my_pointer = &Harl::warning;
        break ;
    default:
        my_pointer = &Harl::invalid;
        break ;
    }
    (this->*my_pointer)();
}
