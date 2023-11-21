# include "Cat.hpp"
# include "Brain.hpp"

Cat::Cat() : Animal("Cat")
{
    try {
        this->brain = new Brain();
    } catch (std::bad_alloc &exp) {
        std::cout << exp.what() << std::endl;
    }
    std::cout << "Cat_default constructor called" << std::endl;
}

Cat::Cat(const Cat &copy)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = copy;
}

Cat &Cat::operator=(const Cat &copy)
{
    std::cout << "Cat assignement operator called" << std::endl;
    this->type = copy.type;
    this->type.append("_copy");
    this->brain = new Brain(*copy.brain);
    return (*this);
}

Cat::~Cat()
{
    if (this->brain)
        delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "MIAOU MIAOU !!" << std::endl;
}
