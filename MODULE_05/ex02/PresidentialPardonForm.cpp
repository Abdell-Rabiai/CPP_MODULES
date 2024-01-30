# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 25, 5), _target("default") { }

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential", 25, 5), _target(target) { }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs)
{
    *this = rhs;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    if (this != &rhs)
        this->_target = rhs._target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() { }

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!this->getIsFormSigned())
        throw AForm::FormNotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    else
        std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

