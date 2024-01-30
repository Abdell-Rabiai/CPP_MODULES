/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:36:28 by arabiai           #+#    #+#             */
/*   Updated: 2024/01/30 12:11:23 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"

int main(void)
{
    try
    {
        Bureaucrat bureaucrat("TABI3A", 1); // a bureaucrat with a grade of 1 : no exception 
        // Bureaucrat bureaucrat("TABI3A", 1); // a bureaucrat with a grade of -2 : exception
        Form form("FORM", 1, 1); // a form with a gradeRequiredToSign of 1 and a gradeRequiredToExecute of 1 : no exception
        // Form form("FORM", 255, 1); // a form with a gradeRequiredToSign of 0 and a gradeRequiredToExecute of 1 : exception
        std::cout << form << std::endl;

        bureaucrat.signForm(form);
        std::cout << "------------------------------>\n\n";
        std::cout << form << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}