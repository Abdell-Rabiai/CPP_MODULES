# ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

/*Abstract class*/
/*
An abstract class is a concept in object-oriented programming (OOP) that serves as a blueprint for other classes.
It is a class that cannot be instantiated on its own and typically contains one or more abstract methods.
Abstract methods are declared in the abstract class but lack an implementation. Instead,
the responsibility of providing an implementation for these methods falls on the concrete (derived) classes that inherit from the abstract class.
*/
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
        virtual void makeSound() const = 0; // pure virtual method or abstract method
        // / A pure virtual function or pure virtual method is a virtual function that is required to be implemented by a derived class if the derived class is not abstract.
};

#endif // ANIMAL_HPP

/*
    in this class we have a protected constructor, which means that we can't create an Animal object directly,
    but we can create derived classes from it.
    we have a virtual method makeSound() which will be overriden in the derived classes.
    we have a virtual destructor, which means that when we delete an object of a derived class through a pointer to the base class,
    the destructor of the derived class will be called first, and then the destructor of the base class.
*/