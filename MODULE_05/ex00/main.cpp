/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:36:28 by arabiai           #+#    #+#             */
/*   Updated: 2024/01/30 10:19:00 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int main(void)
{
    // exemple 1: degrading the grade of a bureaucrate: creating a Bureaucrat with a grade that is too high
    try
    {
        Bureaucrat b("TABI3A", 150);
        std::cout << b << std::endl;
        b.incrementGrade();
        // b.decrementGrade(); this will throw an exception too low
        std::cout << b << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    // exemple 2: upgrading the grade of a bureaucrate: creating a Bureaucrat with a grade that is too low
    try
    {
        Bureaucrat b("TABI3A", 1);
        std::cout << b << std::endl;
        b.decrementGrade();
        // b.incrementGrade(); this will throw an exception too high
        std::cout << b << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}