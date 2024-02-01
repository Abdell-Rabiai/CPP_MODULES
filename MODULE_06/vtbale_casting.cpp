#include <iostream>

class Animal {
public:
    virtual void sound() {
        std::cout << "Animal::sound" << std::endl;
    }
    virtual void eat() {
        std::cout << "Animal::eat" << std::endl;
    }
    virtual void sleep() {
        std::cout << "Animal::sleep" << std::endl;
    }
    virtual ~Animal() {}
    // hidden virtual pointer (vptr) as its first member
    VTable* vptrAnimal;
};

class Dog : public Animal {
public:
    void sound() override {
        std::cout << "Dog::sound" << std::endl;
    }
    void eat() override {
        std::cout << "Dog::eat" << std::endl;
    }
    void sleep() override {
        std::cout << "Dog::sleep" << std::endl;
    }
    ~Dog() {}
    // hidden virtual pointer (vptr) as its first member
    VTable* vptrDog;
};

int main() {
    Animal* ptr = new Dog;
    ptr->sound();  // Calls Dog::sound at runtime
    ptr->eat();  // Calls Dog::eat at runtime
    ptr->sleep();  // Calls Dog::sleep at runtime

    delete ptr;
    return 0;
}
/*
The compiler might create a vtable for each class that contains virtual functions.
The vtable is essentially an array of function pointers
where each slot corresponds to a virtual function in the class.
*/

// Simplified representation of vtable
struct VTable {
    void (*sound)();
    void (*eat)();
    void (*sleep)();
};

// VTable for Animal class: an array of function pointers to the virtual functions of Animal
VTable AnimalVTable = {&Animal::sound, &Animal::eat, &Animal::sleep};

// VTable for Dog class (derived from Animal): an array of function pointers to the virtual functions of Dog
VTable DogVTable = {&Dog::sound, &Dog::eat, &Dog::sleep};

/*
vptr (Virtual Pointer):
Each object of a class with virtual functions may have a hidden virtual pointer (vptr) as its first member.
The vptr points to the vtable associated with the actual type of the object.
*/

// when i create an object of type Dog, the compiler will create a vptr as its first and hidden member
// the vptr will point to the vtable of the Dog class

Animal* dog = new Dog;
// inside the constructor of Dog class, the compiler will do something like this:
// initialize the vptr of the object dog to point to the vtable of the Dog class
dog->vptrDog = &DogVTable;
// so when i call a virtual function through a base class pointer, the vptr is used to determine the correct function to call at runtime
// like this:
// when i do this:
dog->sound();
// the compiler will do something like this:
// get the vptr of the object dog
VTable* vptr = dog->vptrDog;
// get the first function pointer in the vtable of the Dog class
void (*sound)() = vptr->sound;
// call the function pointed to by the function pointer
sound();
// so 
/*this statement:*/ dog->sound(); /*is equivalent to this*/ dog->vptrDog->sound();
/*and this statement:*/ dog->eat(); /*is equivalent to this*/ dog->vptrDog->eat();
/*and this statement:*/ dog->sleep(); /*is equivalent to this*/ dog->vptrDog->sleep();


/*******************************************************************************************************************************************************************/
// same thhing for Animal class
Animal* animal = new Animal;
// inside the constructor of Animal class, the compiler will do something like this:
// initialize the vptr of the object animal to point to the vtable of the Animal class
animal->vptrAnimal = &AnimalVTable;
// so when i call a virtual function through a base class pointer, the vptr is used to determine the correct function to call at runtime
// like this:
// when i do this:
animal->sound();
// the compiler will do something like this:
// get the vptr of the object animal
VTable* vptr = animal->vptrAnimal;
// get the first function pointer in the vtable of the Animal class
void (*sound)() = vptr->sound;
// call the function pointed to by the function pointer
sound();
// so
/*this statement:*/ animal->sound(); /*is equivalent to this*/ animal->vptrAnimal->sound();

// all of this is done by the compiler behind the scenes
// and he does this base on the actual type of the object pointed to by the pointer
// so if i do this:
Animal* ptr = new Dog; // the type of the object pointed to by ptr is Dog
Animal* ptr = new Animal; // the type of the object pointed to by ptr is Animal
// buuuuut
Animal animal;
Dog dog;
Cat cat;
// the type of the object pointed to by ptr is Animal an dthis one is determined at compile time
// so we will not need the vptr in this case



// STATIC CAST VS DYNAMIC CAST
/*******************************************************************************************************************************************************************/

// static_cast and dynamic_cast are two of the C++ casting operators that play a role in managing types and conversions,
// especially in the context of polymorphism and type hierarchies.
1.static_cast OR Compile-time cast
// is primarily used for conversions between numeric types (e.g. int to float, int to double, etc) and primitive types (e.g. int to char*, int to void*, etc).
// It can also be used to cast pointers or references to base classes up to derived classes. (upcasting)
// It is often used for non-polymorphic conversions, like converting between related types or fundamental types.
// exemple:
int i = 9;
float f = static_cast<float>(i);

void* p = &i;
int* pi = static_cast<int*>(p); // Not Correct

char c = 'a';
int* p = static_cast<int*>(&c); // compile-time error we can't convert a char* to an int* using static_cast because they are not related types (no inheritance relationship between them)

Dog dog;
Animal* animal = static_cast<Animal*>(&dog); // upcasting from derived class to base class is allowed using static_cast
// this considered safe because we are casting from a derived class to a base class and the type is known at compile time

2.dynamic_cast OR Runtime cast
// is primarily used for conversions between pointers to related classes that have virtual functions, up and down the inheritance hierarchy.
// It is used for converting pointers and references at runtime.
// it is used to check the actual type of an object at runtime. and perform a safe downcast.

// exemple:

Animal* animal = new Dog;
Dog* dog = dynamic_cast<Dog*>(animal); // downcasting from base class to derived class is allowed using dynamic_cast
if (dog) {
    // the cast was successful
    // use dog
}
else {
    // the cast failed
    // handle the error
}

/*
static_cast in Polymorphism:

static_cast is often used for upcasting (casting from derived to base) when the type is known at compile time. 
It doesn't perform runtime checks for polymorphic types.
If you use static_cast for downcasting (casting from base to derived), it doesn't perform runtime type checks. 
It relies on the programmer's assurance of correctness.

dynamic_cast in Polymorphism:
dynamic_cast is essential for safely downcasting in polymorphic hierarchies. It performs runtime type checks.
When you perform a dynamic_cast to a derived type, it checks whether the object is of the specified type and returns
a valid pointer if the conversion is safe. If not, it returns a null pointer.
*/

