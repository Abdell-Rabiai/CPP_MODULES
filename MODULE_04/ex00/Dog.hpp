# ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog &copy);
        Dog &operator=(const Dog &copy);
        ~Dog();
        void makeSound() const; // override is c++11 feature; it could have been void makeSound() const override
};

#endif // DOG_HPP