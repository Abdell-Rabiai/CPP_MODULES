# include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _SignGrade(150), _ExecuteGrade(150) { }

AForm::AForm(const std::string name, const int SignGrade, const int ExecuteGrade) : _name(name), _signed(false), _SignGrade(SignGrade), _ExecuteGrade(ExecuteGrade)
{
    if (SignGrade < 1 || ExecuteGrade < 1)
        throw AForm::GradeTooHighException();
    else if (SignGrade > 150 || ExecuteGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& rhs) : _name(rhs._name), _signed(rhs._signed), _SignGrade(rhs._SignGrade), _ExecuteGrade(rhs._ExecuteGrade) { }

AForm::~AForm() { }

AForm & AForm::operator=(const AForm& rhs)
{
    if (this != &rhs)
        this->_signed = rhs._signed;
    return (*this);
}

const std::string	AForm::getName() const
{
    return (this->_name);
}

bool    AForm::getSigned() const
{
    return (this->_signed);
}

int		AForm::getGradeToSign() const
{
    return (this->_SignGrade);
}

int		AForm::getGradeToExecute() const
{
    return (this->_ExecuteGrade);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->_SignGrade)
        throw AForm::GradeTooLowException();
    else
        this->_signed = true;
}

const char*	AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

const char*	AForm::FormNotSignedException::what() const throw()
{
    return ("Form not signed yet");
}

std::ostream & operator<<(std::ostream & out, AForm const & rhs)
{
    out << "THE AFORM'S NAME IS: {" << rhs.getName() << "}" <<std::endl;
    out << "THE AFORM'S SIGN GRADE IS: {" << rhs.getGradeToSign() << "}" <<std::endl;
    out << "THE AFORM'S EXECUTE GRADE IS: {" << rhs.getGradeToExecute() << "}" <<std::endl;
    out << "THE AFORM'S SIGN STATUS IS: {" << rhs.getSigned() << "}" <<std::endl;
    return (out);
}