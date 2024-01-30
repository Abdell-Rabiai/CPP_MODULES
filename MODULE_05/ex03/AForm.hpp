# pragma once

# include <iostream>
# include <string>
# include <exception>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string	_name;
        bool				_formStatus;
        const int			_SignRequiredToGrade;
        const int			_SignRequiredToExecute;

    public:
        AForm();
        AForm(const std::string name, const int SignGrade, const int ExecuteGrade);
        AForm(const AForm& rhs);
        virtual ~AForm();

        AForm & operator=(const AForm& rhs);

        const std::string	getName() const;
        bool				getIsFormSigned() const;
        int					getGradeToSign() const;
        int					getGradeToExecute() const;

        void				beSigned(const Bureaucrat& bureaucrat);
        virtual void		execute(const Bureaucrat& executor) const = 0;

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

        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char*	what() const throw();
        };
};

std::ostream & operator<<(std::ostream & out, AForm const & rhs);