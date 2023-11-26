# include <iostream>
# ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP


class WrongAnimal
{
    protected:
        std::string _type;

    public:
        WrongAnimal();
        WrongAnimal(std::string type);

        WrongAnimal(const WrongAnimal &rhs);
        WrongAnimal &operator=(const WrongAnimal &rhs);

        ~WrongAnimal();
        std::string getType() const;
        void makeSound() const;
    // here we didn't declare the makeSound() function as virtual because we don't want to override it in the derived classes
    // we want to keep the same implementation for all the derived classes in order to make the wrongCat output the same as the wrongAnimal
    // as asked in the subject
};

# endif // !WRONGANIMAL_HPP