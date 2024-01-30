# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), _target("default") { }

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45), _target(target) { }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs)
{
    *this = rhs;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    if (this != &rhs)
        this->_target = rhs._target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() { }

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!this->getIsFormSigned())
        throw AForm::FormNotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    else
    {
        std::srand(std::time(NULL));
        int randomNumber = std::rand();
        std::cout << "*** drilling noises ***" << std::endl;
        if (randomNumber % 2 == 0) // 50% chance of success : either true or false
            std::cout << this->_target << " Has Been Robotomized Successfully" << std::endl;
        else
            std::cout << this->_target << " Has NOT Been Robotomized" << std::endl;
    }
}


