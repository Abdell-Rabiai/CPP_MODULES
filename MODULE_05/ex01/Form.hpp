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
        const std::string	_name;
        bool				_signed;
        const int			_SignGrade;
        const int			_ExecuteGrade;

    public:
        Form();
        Form(const std::string name, const int SignGrade, const int ExecuteGrade);
        Form(const Form& rhs);
        ~Form();

        Form & operator=(const Form& rhs);

        const std::string	getName() const;
        bool				getSigned() const;
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