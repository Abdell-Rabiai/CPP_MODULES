# include "Intern.hpp"


Intern::Intern() {}

Intern::Intern(Intern const & rhs) {
    *this = rhs;
}

Intern::~Intern() {}

Intern & Intern::operator=(Intern const & rhs) {
    if (this != &rhs) {
    }
    return *this;
}

const char*	Intern::FormNotFoundException::what() const throw() {
    return ("Intern Could not make the requested form exception\n");
}


unsigned int customHash(const std::string& input) {
    unsigned int hash = 0;

    for (size_t i = 0; i < input.length(); i++) {
        hash = (hash * 7) + (unsigned int)(input[i]);
    }
    return hash;
}

AForm *Intern::makeForm(std::string const & formName, std::string const & target) const {
    AForm *form = NULL;
    unsigned int hashed_name = customHash(formName);
    // robotomy request ==> 2477014416
    // shrubbery request ==> 2088557347
    // presidential pardon ==> 1317752587
    switch (hashed_name) {
        case 2477014416:
            form = new RobotomyRequestForm(target);
            break;
        case 2088557347:
            form = new ShrubberyCreationForm(target);
            break;
        case 1317752587:
            form = new PresidentialPardonForm(target);
            break;
        default:
            throw Intern::FormNotFoundException();
    }
    return form;
}