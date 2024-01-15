# pragma once 

# include "AForm.hpp"
# include <cstdlib>

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const & rhs);
        PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);
        ~PresidentialPardonForm();

        void execute(Bureaucrat const & executor) const;
};