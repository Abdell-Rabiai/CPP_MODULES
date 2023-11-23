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

        WrongAnimal(const WrongAnimal &copy);
        WrongAnimal &operator=(const WrongAnimal &copy);

        ~WrongAnimal();
        std::string getType() const;
        void makeSound() const;
};

# endif // !WRONGANIMAL_HPP