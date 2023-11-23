#include <string_view>
# include <iostream>
# include <string>

class Animal
{
    protected:
        std::string m_name;

        // We're making this constructor protected because
        // we don't want people creating Animal objects directly,
        // but we still want derived classes to be able to use it.
        Animal(std::string_view name) : m_name(name) {
            std::cout << "Animal def constructor called" << std::endl;
        }

        // To prevent slicing (covered later)
        Animal(const Animal&) = default;
        Animal& operator=(const Animal&) = default;

    public:
        std::string_view getName() const { return m_name; }
        std::string_view speak() const { return "???"; }
};

class Cat: public Animal
{
    public:
        Cat(std::string_view name) : Animal(name) {
        }

    std::string_view speak() const { return "Meow"; }
};

class Dog: public Animal
{
    public:
        Dog(std::string_view name) : Animal(name) {
        }

    std::string_view speak() const { return "Woof"; }
};

class Horse: public Animal
{
    public:
        Horse(std::string_view name) : Animal(name) {
        }

    std::string_view speak() const { return "Neigh"; }
};

void report(const Cat &cat)
{
    std::cout << cat.getName() << " says " << cat.speak() << '\n';
}

void report(const Dog &dog)
{
    std::cout << dog.getName() << " says " << dog.speak() << '\n';
}
/*
However, because Cat and Dog are derived from Animal, Cat and Dog have an Animal part.
Therefore, it makes sense that we should be able to do something like this:
*/
void report(const Animal &animal)
{
    std::cout << animal.getName() << " says " << animal.speak() << '\n';
}
/*
This would let us pass in any class derived from Animal, even ones that we created after we wrote the function!
Instead of one function per derived class, we get one function that works with all classes derived from Animal!
The problem is, of course, that because rAnimal is an Animal reference,
rAnimal.speak() will call Animal::speak() instead of the derived version of speak() and it will always say ????.

Second, let’s say you had 3 cats and 3 dogs that you wanted to keep in an array for easy access.
Because arrays can only hold objects of one type,without a pointer or reference to a base class.
you’d have to create a different array for each derived type
*/
Cat cats[3] = { Cat("Whiskers"), Cat("Mittens"), Cat("Fluffy") };
for (int i = 0; i < 3; ++i)
    report(cats[i]);
Dog dogs[3] = { Dog("Whiskers"), Dog("Mittens"), Dog("Fluffy") };
for (int i = 0; i < 3; ++i)
    report(dogs[i]);
/*
Now, consider what would happen if you had 30 different types of animals. You’d need 30 arrays, one for each type of animal!
a big waste of time and space.
so the solution is to use a pointer or reference to a base class.
*/

// However, because both Cat and Dog are derived from Animal, we can use Animal* pointers to point to Cat and Dog objects:
    // set up the cats objects
    Cat fred{ "Fred" };
    Cat misty{ "Misty" };
    Cat zeke{ "Zeke" };
    // set up the dogs objects
    Dog garbo{ "Garbo" };
    Dog pooky{ "Pooky" };
    Dog truffle{ "Truffle" };

    // set up an array of pointers to animals, and set those pointers to our Cat and Dog objects
    Animal *animals[]{ &fred, &garbo, &misty, &pooky, &truffle, &zeke };
    for (int i=0; i < 6; ++i)
        std::cout << animals[i]->getName() << " says " << animals[i]->speak() << '\n';
/*
While this compiles and executes, unfortunately the fact that each element of array “animals”
is a pointer to an Animal means that animal->speak() will call Animal::speak()
instead of the derived class version of speak() that we want. The output will be "???\n" * 6
now we have to find a way to make each object in the array call its own speak() function.
the solution is to make the speak() function virtual.
The virtual keyword indicates that this function is meant to be overridden by derived classes. 
what happens when we make a function virtual is that the compiler will no longer bind that function call to the function call at compile time

This is known as polymorphism, where a pointer or reference to a base class can be used to refer to objects of its derived classes,
and the correct version of the overridden function is called based on the actual type of the object being pointed to or referred to.

*/

int main()
{
    const Cat cat("Fred");
    report(cat);
    // std::cout << "cat is named " << cat.getName() << ", and it says " << cat.speak() << '\n';

    const Dog dog( "Garbo" );
    report(dog);
    // std::cout << "dog is named " << dog.getName() << ", and it says " << dog.speak() << '\n';

    // const Animal* pAnimal( &cat );
    // std::cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << '\n';

    // pAnimal = &dog;
    // std::cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << '\n';

    return 0;
}
/*
We see the same issue here. Because pAnimal is an Animal pointer, it can only see the Animal portion of the class.
Consequently, pAnimal->speak() calls Animal::speak() rather than the Dog::Speak() or Cat::speak() function.
*/

/*
        THE MECANISM OF VIRTUAL FUNCTIONS
Under the hood, polymorphism and dynamic dispatch with virtual functions are typically implemented using a mechanism called the virtual function table (vtable) and a pointer to this table.

Virtual Function Table (vtable):

When a class contains at least one virtual function, the compiler typically creates a virtual function table for that class.
The vtable is a table of function pointers, one for each virtual function in the class.
Each instance of a class with virtual functions contains a hidden pointer to its vtable.
Pointer to vtable:

When an object is created, a hidden pointer, often referred to as the "vpointer" or "vptr," is added to the object.
This vpointer points to the vtable associated with the class of the object.
Dynamic Dispatch:

When you call a virtual function on an object through a pointer or reference, the program uses the vpointer to find the vtable.
From the vtable, it looks up the address of the appropriate virtual function.
The function is then called, and the correct version of the function for the actual type of the object is executed.

*/

