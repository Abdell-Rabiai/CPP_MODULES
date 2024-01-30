# include "Form.hpp"

Form::Form() : _name("default"), _formStatus(false), _SignRequiredToGrade(150), _SignRequiredToExecute(150) { }

Form::Form(const std::string name, const int SignGrade, const int ExecuteGrade) : _name(name), _formStatus(false), _SignRequiredToGrade(SignGrade), _SignRequiredToExecute(ExecuteGrade)
{
    if (SignGrade < 1 || ExecuteGrade < 1)
        throw Form::GradeTooHighException();
    else if (SignGrade > 150 || ExecuteGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& rhs) : _name(rhs._name), _formStatus(rhs._formStatus), _SignRequiredToGrade(rhs._SignRequiredToGrade), _SignRequiredToExecute(rhs._SignRequiredToExecute) { }

Form::~Form() { }

Form & Form::operator=(const Form& rhs)
{
    if (this != &rhs)
        this->_formStatus = rhs._formStatus;
    return (*this);
}

const std::string	Form::getName() const
{
    return (this->_name);
}

bool    Form::getIsFormSigned() const
{
    return (this->_formStatus);
}

int		Form::getGradeToSign() const
{
    return (this->_SignRequiredToGrade);
}

int		Form::getGradeToExecute() const
{
    return (this->_SignRequiredToExecute);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->_SignRequiredToGrade)
        throw Form::GradeTooLowException();
    else
        this->_formStatus = true;
}

const char*	Form::GradeTooHighException::what() const throw()
{
    return ("Form's Required Grade is too high");
}

const char*	Form::GradeTooLowException::what() const throw()
{
    return ("Form's Required Grade is too low");
}

std::ostream & operator<<(std::ostream & out, Form const & rhs)
{
    out << "THE FORM'S NAME IS: {" << rhs.getName() << "}" <<std::endl;
    out << "THE FORM'S SIGN GRADE IS: {" << rhs.getGradeToSign() << "}" <<std::endl;
    out << "THE FORM'S EXECUTE GRADE IS: {" << rhs.getGradeToExecute() << "}" <<std::endl;
    out << "THE FORM'S SIGN STATUS IS: {" << rhs.getIsFormSigned() << "}" <<std::endl;
    return (out);
}