# pragma once 

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(Intern const & rhs);
        ~Intern();

        Intern & operator=(Intern const & rhs);

        AForm *makeForm(std::string const & form_name, std::string const & target) const;

        class FormNotFoundException : public std::exception
        {
            public:
                virtual const char*	what() const throw();
        };
};

unsigned int customHash(const std::string& input);