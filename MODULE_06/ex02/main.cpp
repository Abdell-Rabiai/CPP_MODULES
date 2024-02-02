/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:18:42 by arabiai           #+#    #+#             */
/*   Updated: 2024/02/01 16:29:44 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "identifyType.hpp"

int main()
{
    Base *base = generatePointerOfBase();
    identifyTheTypeOfPointer(base);
    identifyTheTypeOfReference(*base);
    delete base;
    return (0);
}