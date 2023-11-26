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
        // the virtual keyword is not mandatory here because there is a virtual function in the class
        // but the virtual destructor is a must have in case of inheritance to ensure that the correct destructor is called
        // when deleting a pointer to a base class that points to a derived class
        std::string getType() const;
        void setType(std::string type);
        virtual void makeSound() const;
};

#endif // ANIMAL_HPP