# ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
    protected:
        std::string type;

    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal &copy);
        Animal &operator=(const Animal &copy);

        virtual ~Animal();
        // here we make the destructor virtual because we are going to use polymorphism
        // in case we will have a pointer of type Animal that will point to an object of type Dog or Cat
        // and we will delete this pointer, the destructor of the base class will be called
        // and if the destructor of the base class is not virtual, the destructor of the derived class will not be called
        // and we will have a memory leaks
        std::string getType() const;
        void setType(std::string type);
        virtual void makeSound() const;
};

#endif // ANIMAL_HPP