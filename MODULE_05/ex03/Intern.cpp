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
    return ("Exception: Intern Could not make the requested form\n");
}


int getIndex(const std::string& input) {
    std::string str[3] = {"robotomy request", "shrubbery request", "presidential request"};
    for (size_t i = 0; i < 3; i++) {
        if (str[i] == input)
            return i + 1;
    }
    return -1;
}

AForm *Intern::makeForm(std::string const & formName, std::string const & target) const {
    AForm *form = NULL;
    int index = getIndex(formName);

    switch (index) {
        case 1:
            form = new RobotomyRequestForm(target);
            break;
        case 2:
            form = new ShrubberyCreationForm(target);
            break;
        case 3:
            form = new PresidentialPardonForm(target);
            break;
        default:
            throw Intern::FormNotFoundException();
    }
    std:: cout << "the form has been created by successfully by an intern" << std::endl;
    return form;
}