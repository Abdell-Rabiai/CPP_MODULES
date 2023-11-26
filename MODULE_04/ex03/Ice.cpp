# include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    // std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const std::string &type) : AMateria(type)
{
    // std::cout << "Ice parametrized constructor called" << std::endl;
}

Ice::Ice(const Ice &copy)
{
    // std::cout << "Ice copy constructor called" << std::endl;
    *this = copy;
}

Ice &Ice::operator=(const Ice &copy)
{
    // std::cout << "Ice assignement operator called" << std::endl;
    if (this != &copy) {
        this->setType(copy.getType());
    }
    return (*this);
}

Ice::~Ice()
{
    // std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
    Ice *cloned_ice = new Ice(*this);
    return (cloned_ice);
}

void Ice::use(ICharacter& target)
{
    std::cout << "\001\033[1;36m\002[ * shoots an ice bolt at {" << target.getName() << "} * ]\001\033[0m\002\n" << std::endl;
}
