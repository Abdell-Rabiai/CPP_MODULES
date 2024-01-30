# pragma once 

# include "AForm.hpp"
# include <cstdlib>

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
        PresidentialPardonForm();

    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const & rhs);
        PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);
        ~PresidentialPardonForm();

        virtual void execute(Bureaucrat const & executor) const;
};