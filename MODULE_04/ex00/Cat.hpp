# ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat &copy);
        Cat &operator=(const Cat &copy);
        ~Cat();
        void makeSound() const; // override is c++11 feature; it could have been void makeSound() const override
        // to indicate that it is overriding a virtual function up in the base class
};

# endif // CAT_HPP