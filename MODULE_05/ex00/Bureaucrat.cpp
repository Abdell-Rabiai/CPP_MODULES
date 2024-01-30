/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:36:35 by arabiai           #+#    #+#             */
/*   Updated: 2024/01/30 11:40:33 by arabiai          ###   ########.fr       */
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
        this->_grade--;
    // Remember. Since grade 1 is the highest one and 150 the lowest,
    // incrementing a grade 3 should give a grade 2 to the bureaucrat.
    // decrementing a grade 3 should give a grade 4 to the bureaucrat.
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade++;
}

const char * Bureaucrat::BureaucratException::what() const throw()
{
    return ("OOps! Something went wrong\n"); // this is a more generic approach (we don't specify if the grade is too high or too low)
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("OOps! TOO HIGH\n"); // this is more specific (we specify that the grade is too high)
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("OOps! TOO LOW\n"); // this is more specific (we specify that the grade is too low)
}


std::ostream & operator<<(std::ostream & out, Bureaucrat const & rhs)
{
    out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
    return (out);
}

