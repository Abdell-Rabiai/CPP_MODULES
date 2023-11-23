# include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    this->type = "Dog"; // this is not necessary
    std::cout << "Dog_default constructor called" << std::endl;
    try {
        this->brain = new Brain();
    }
    catch (std::bad_alloc &exp) {
        std::cout << exp.what() << std::endl;
    }
}

Dog::Dog(Brain *brain) : Animal("Dog")
{
    this->type = "Dog";
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
    std::cout << "Dog_parameterized constructor called" << std::endl;
}

Dog::Dog(const Dog &copy)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = copy;
}

Dog &Dog::operator=(const Dog &rhs)
{
    std::cout << "Dog assignement operator called" << std::endl;
    // deep copy of object rhs to this
    this->type = rhs.type;
    this->type.append("_copy");
    try {
        this->brain = new Brain(*rhs.brain); // this is a deep copy
    }
    catch (std::bad_alloc &exp) {
        std::cout << exp.what() << std::endl;
    }
    // this->brain = rhs.brain; // this is a shallow copy
    // in the shallow copy we have two pointers pointing to the same memory address
    // if we delete one of them, the other one will be pointing to a memory address that is not allocated
    // and it will cause a segmentation fault or a abort but in the deep copy we have two pointers pointing to two different memory addresses
    // so we will have to delete both of them to avoid memory leaks (delete this dog and delete rhs dog)
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog_destructor called" << std::endl;
    if (this->brain)
        delete this->brain;
}

void Dog::makeSound() const
{
    std::cout << "BARK BARK !!" << std::endl;
}

