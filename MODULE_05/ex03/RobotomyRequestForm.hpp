# pragma once

# include "AForm.hpp"
# include <cstdlib>

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const & rhs);
        RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const & executor) const;
};