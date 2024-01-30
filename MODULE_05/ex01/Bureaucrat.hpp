/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:36:32 by arabiai           #+#    #+#             */
/*   Updated: 2024/01/30 11:58:25 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <string>
# include <exception>
# include <stdexcept>
# include "Form.hpp"

class Form;

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
    
        void signForm(Form & form); // the bureaucrat signs the form if his grade is high enough and the form is not already signed
        // high enough means that the bureaucrat's grade must be lower or equal to the form's grade required to be signed

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
