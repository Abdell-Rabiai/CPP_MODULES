# ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
    protected:
        std::string type;
        Animal();
        Animal(std::string type);
        // / We're making this two constructors protected because
        // we don't want people creating Animal objects directly,
        // but we still want derived classes to be able to use it.

    public:
        Animal(const Animal &copy);
        Animal &operator=(const Animal &copy);

        virtual ~Animal();
        std::string getType() const;
        void setType(std::string type);
        virtual void makeSound() const;
};

#endif // ANIMAL_HPP