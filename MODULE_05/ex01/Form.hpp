# pragma once

# include <iostream>
# include <string>
# include <exception>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string	_name; // the name of the form
        bool				_formStatus; // is it signed or not
        const int			_SignRequiredToGrade; // the grade required to sign the form
        const int			_SignRequiredToExecute; // the grade required to execute the form

    public:
        Form();
        Form(const std::string name, const int SignGrade, const int ExecuteGrade);
        Form(const Form& rhs);
        ~Form();

        Form & operator=(const Form& rhs);

        const std::string	getName() const;
        bool				getIsFormSigned() const;
        int					getGradeToSign() const;
        int					getGradeToExecute() const;

        void				beSigned(const Bureaucrat& bureaucrat);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char*	what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char*	what() const throw();
        };
};

std::ostream & operator<<(std::ostream & out, Form const & rhs);