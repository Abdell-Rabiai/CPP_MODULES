/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:36:35 by arabiai           #+#    #+#             */
/*   Updated: 2024/01/30 12:05:40 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) { }

Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & rhs) : _name(rhs._name)
{
    *this = rhs;
}

Bureaucrat::~Bureaucrat() { }

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
    if (this != &rhs)
        this->_grade = rhs._grade;
    return (*this);
}

std::string const & Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade--; // Remember. Since grade 1 is the highest one and 150 the lowest,
    // incrementing a grade 3 should give a grade 2 to the bureaucrat.
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade++;
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("OOps! TOO HIGH\n");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("OOps! TOO LOW\n");
}

std::ostream & operator<<(std::ostream & out, Bureaucrat const & rhs)
{
    out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
    return (out);
}

void Bureaucrat::signForm(Form & form)
{
    form.beSigned(*this);
    if (form.getIsFormSigned())
        std::cout << this->getName() << " signs " << form.getName() << std::endl;
    else
        std::cout << this->getName() << " cannot sign " << form.getName() << " because " << this->getName() << "'s grade is too low than the form's grade required to be signed" << std::endl;
}