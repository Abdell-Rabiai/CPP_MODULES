# include "AMateria.hpp"

AMateria::AMateria() : _type("default_type")
{
    // std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
    // std::cout << "AMateria parametrized constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
    // std::cout << "AMateria copy constructor called" << std::endl;
    *this = copy;
}

AMateria &AMateria::operator=(const AMateria &copy)
{
    // std::cout << "AMateria assignement operator called" << std::endl;
    if (this != &copy) {
        this->_type = copy._type;
    }
    return (*this);
}

AMateria::~AMateria()
{
    // std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
    return (this->_type);
}

void AMateria::setType(std::string const & type)
{
    this->_type = type;
}

void AMateria::use(ICharacter& target)
{
    // default implementation, do nothing but it will be overriden by the inherited classes
    std::cout << "AMateria of type {" << this->_type << "} used on {" << target.getName() <<"} "<< std::endl;
}
