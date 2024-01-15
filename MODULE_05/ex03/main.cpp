/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:36:28 by arabiai           #+#    #+#             */
/*   Updated: 2024/01/15 11:31:09 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Intern.hpp"

int main()
{
    try
    {
        Intern someRandomIntern;
        AForm* rrf;
        // rrf = someRandomIntern.makeForm("sss request", "Bender");
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std:: cout << "{the form below has been created by an intern}\n" << std::endl;
        std::cout << *rrf << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}