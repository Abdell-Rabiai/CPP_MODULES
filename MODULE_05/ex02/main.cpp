/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:36:28 by arabiai           #+#    #+#             */
/*   Updated: 2024/01/13 21:31:55 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"

int main(void)
{
    Bureaucrat *bureaucrat = new Bureaucrat("Tabi3a", 1);
    Form *form = new Form("Form", 1, 1);

    std::cout << *bureaucrat << std::endl;
    std::cout << *form << std::endl;

    try
    {
        bureaucrat->signForm(*form);
        std::cout << *form << std::endl;
        bureaucrat->signForm(*form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    delete bureaucrat;
    delete form;
    return (0);
}