/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:36:32 by arabiai           #+#    #+#             */
/*   Updated: 2024/01/13 21:16:05 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <string>
# include <exception>
# include <stdexcept>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        std::string const _name;
        int _grade; // 1 - 150
    
    public:
        Bureaucrat();
        Bureaucrat(std::string const & name, int grade);
        Bureaucrat(Bureaucrat const & rhs);
        ~Bureaucrat();

        Bureaucrat & operator=(Bureaucrat const & rhs);

        std::string const & getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();
        
        void signForm(AForm & form);
        void executeForm(AForm const & form);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };

};

std::ostream & operator<<(std::ostream & out, Bureaucrat const & rhs);
