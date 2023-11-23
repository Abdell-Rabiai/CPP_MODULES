# ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain *brain;

    public:
        Cat();
        Cat(Brain *brain);
        Cat(const Cat &copy);
        Cat &operator=(const Cat &copy);
        ~Cat();
        void makeSound() const; // override is c++11 feature; it could have been void makeSound() const override
};

# endif // CAT_HPP