# include "AForm.hpp"

AForm::AForm() : _name("default"), _formStatus(false), _SignRequiredToGrade(150), _SignRequiredToExecute(150) { }

AForm::AForm(const std::string name, const int SignGrade, const int ExecuteGrade) : _name(name), _formStatus(false), _SignRequiredToGrade(SignGrade), _SignRequiredToExecute(ExecuteGrade)
{
    if (SignGrade < 1 || ExecuteGrade < 1)
        throw AForm::GradeTooHighException();
    else if (SignGrade > 150 || ExecuteGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& rhs) : _name(rhs._name), _formStatus(rhs._formStatus), _SignRequiredToGrade(rhs._SignRequiredToGrade), _SignRequiredToExecute(rhs._SignRequiredToExecute) { }

AForm::~AForm() { }

AForm & AForm::operator=(const AForm& rhs)
{
    if (this != &rhs)
        this->_formStatus = rhs._formStatus;
    return (*this);
}

const std::string	AForm::getName() const
{
    return (this->_name);
}

bool    AForm::getIsFormSigned() const
{
    return (this->_formStatus);
}

int		AForm::getGradeToSign() const
{
    return (this->_SignRequiredToGrade);
}

int		AForm::getGradeToExecute() const
{
    return (this->_SignRequiredToExecute);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->_SignRequiredToGrade)
        throw AForm::GradeTooLowException();
    else
        this->_formStatus = true;
}

const char*	AForm::GradeTooHighException::what() const throw()
{
    return ("Exception: Grade too high");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
    return ("Exception: Grade too low");
}

const char*	AForm::FormNotSignedException::what() const throw()
{
    return ("Exception: Form is not signed yet\n");
}

std::ostream & operator<<(std::ostream & out, AForm const & rhs)
{
    out << "THE AFORM'S NAME IS: {" << rhs.getName() << "}" <<std::endl;
    out << "THE AFORM'S SIGN GRADE IS: {" << rhs.getGradeToSign() << "}" <<std::endl;
    out << "THE AFORM'S EXECUTE GRADE IS: {" << rhs.getGradeToExecute() << "}" <<std::endl;
    out << "THE AFORM'S SIGN STATUS IS: {" << rhs.getIsFormSigned() << "}" <<std::endl;
    return (out);
}