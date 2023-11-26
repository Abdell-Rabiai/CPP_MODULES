# include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    // std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const std::string &type) : AMateria(type)
{
    // std::cout << "Cure parametrized constructor called" << std::endl;
}

Cure::Cure(const Cure &copy)
{
    // std::cout << "Cure copy constructor called" << std::endl;
    *this = copy;
}

Cure &Cure::operator=(const Cure &copy)
{
    // std::cout << "Cure assignement operator called" << std::endl;
    if (this != &copy) {
        this->setType(copy.getType());
    }
    return (*this);
}

Cure::~Cure()
{
    // std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
    Cure *cloned_cure = new Cure(*this);
    return (cloned_cure);
}

void Cure::use(ICharacter& target)
{
    std::cout << "\001\033[1;32m\002[ * heals " << target.getName() << "'s wounds * ]\001\033[0m\002\n" << std::endl;
}
