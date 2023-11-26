# include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat_default constructor called" << std::endl;
    this->brain = new Brain();
}

Cat::Cat(Brain *brain) : Animal("Cat")
{
    if (brain == NULL){
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

Cat::Cat(const Cat &copy)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->brain = NULL;
    *this = copy;
}

Cat &Cat::operator=(const Cat &rhs)
{
    std::cout << "Cat assignement operator called" << std::endl;
    this->type = rhs.type;
    try {
        if (this->brain)
            delete this->brain;
        this->brain = new Brain(*rhs.brain); // this is a deep copy
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
