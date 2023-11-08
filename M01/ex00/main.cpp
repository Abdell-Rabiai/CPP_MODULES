# include "Zombie.hpp"

int main()
{

    randomChump("Stack_Zombie");

    std::cout << "\n------------------------------------------------------\n" << std::endl;

    Zombie *zombie2 = newZombie("Heap_Zombie");
    zombie2->announce();


    std::cout << "\n-------------------Destructors----------------->\n" << std::endl;
    delete zombie2;
    return 0;
}