/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:36:28 by arabiai           #+#    #+#             */
/*   Updated: 2024/01/30 13:19:37 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

int main(void)
{

	try
	{
		Bureaucrat *bureaucrat = new Bureaucrat("Tabi3a", 5);
		// AForm *form = new RobotomyRequestForm("formulaire");
		// AForm *form = new PresidentialPardonForm("formulaire");
		AForm *form = new ShrubberyCreationForm("formulaire");
		std::cout << "before signing : -----------------------------------------------------------------------\n" << std::endl;
		std::cout << "--------------bureaucrat---------->" << std::endl;
		std::cout << *bureaucrat << std::endl;
		std::cout << "--------------form---------------->" << std::endl;
		std::cout << *form << std::endl;
		
		std::cout << "after signing : -----------------------------------------------------------------------\n" << std::endl;

		bureaucrat->signForm(*form);
		std::cout << *form << std::endl;
		
		std::cout << "execute : -----------------------------------------------------------------------\n" << std::endl;
		form->execute(*bureaucrat);
		
		delete bureaucrat;
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	return (0);
}