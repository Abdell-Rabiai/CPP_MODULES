# include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "";
}

Brain::Brain(std::string ideas[100])
{
    std::cout << "Brain constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = ideas[i];
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &rhs)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = rhs;
}

Brain &Brain::operator=(const Brain &rhs)
{
    std::cout << "Brain assignement operator called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = rhs.ideas[i];
    return (*this);
}
