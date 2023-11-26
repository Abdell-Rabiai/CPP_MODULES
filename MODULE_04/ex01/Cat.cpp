# include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat_default constructor called" << std::endl;
    this->brain = new Brain();
}

Cat::Cat(Brain *brain) : Animal("Cat")
{
    if (brain == NULL) {
        try {
            this->brain = new Brain();
        }
        catch (std::bad_alloc &exp) {
            std::cout << exp.what() << std::endl;
        }
    }
    else
        this->brain = brain;
    std::cout << "Cat_parameterized constructor called" << std::endl;
}

Cat::Cat(const Cat &rhs)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = rhs;
}

Cat &Cat::operator=(const Cat &rhs)
{
    std::cout << "Cat assignement operator called" << std::endl;
    this->type = rhs.type;
    if (this->brain)
        delete this->brain;
    try {
        this->brain = new Brain(*rhs.brain);
        // this is a deep copy because i'm allocating memory for a new
        // Brain object and then copying the content of the rhs.brain into it
        // i could have done this->brain = rhs.brain but that would be a shallow copy
        // in which case both this->brain and rhs.brain would be pointing to the same memory location
        // and if i delete this->brain, rhs.brain would be pointing to a deleted memory location
        // the program will abort
    }
    catch (std::bad_alloc &exp) {
        std::cout << exp.what() << std::endl;
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat_destructor called" << std::endl;
    if (this->brain)
        delete this->brain;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow !!!" << std::endl;
}
