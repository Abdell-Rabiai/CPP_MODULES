# pragma once

# include "AForm.hpp"
# include <cstdlib>

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
        RobotomyRequestForm();

    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const & rhs);
        RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);
        ~RobotomyRequestForm();

        virtual void execute(Bureaucrat const & executor) const;
};