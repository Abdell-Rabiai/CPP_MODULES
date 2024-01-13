# include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _SignGrade(150), _ExecuteGrade(150) { }

Form::Form(const std::string name, const int SignGrade, const int ExecuteGrade) : _name(name), _signed(false), _SignGrade(SignGrade), _ExecuteGrade(ExecuteGrade)
{
    if (SignGrade < 1 || ExecuteGrade < 1)
        throw Form::GradeTooHighException();
    else if (SignGrade > 150 || ExecuteGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& rhs) : _name(rhs._name), _signed(rhs._signed), _SignGrade(rhs._SignGrade), _ExecuteGrade(rhs._ExecuteGrade) { }

Form::~Form() { }

Form & Form::operator=(const Form& rhs)
{
    if (this != &rhs)
        this->_signed = rhs._signed;
    return (*this);
}

const std::string	Form::getName() const
{
    return (this->_name);
}

bool    Form::getSigned() const
{
    return (this->_signed);
}

int		Form::getGradeToSign() const
{
    return (this->_SignGrade);
}

int		Form::getGradeToExecute() const
{
    return (this->_ExecuteGrade);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->_SignGrade)
        throw Form::GradeTooLowException();
    else
        this->_signed = true;
}

const char*	Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char*	Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

std::ostream & operator<<(std::ostream & out, Form const & rhs)
{
    out << "THE FORM'S NAME IS: {" << rhs.getName() << "}" <<std::endl;
    out << "THE FORM'S SIGN GRADE IS: {" << rhs.getGradeToSign() << "}" <<std::endl;
    out << "THE FORM'S EXECUTE GRADE IS: {" << rhs.getGradeToExecute() << "}" <<std::endl;
    out << "THE FORM'S SIGN STATUS IS: {" << rhs.getSigned() << "}" <<std::endl;
    return (out);
}