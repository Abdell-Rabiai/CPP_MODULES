# include "Zombie.hpp"

int main()
{
    int N = 5;
    Zombie *zombies_array = zombieHorde(N, "zombie");
    for (int i = 0; i < N; i++){
        std::cout << "------------------------------------" << std::endl;
        std::cout << "Zombie " << i << " is called \n";
        zombies_array[i].announce();
        std::cout << "------------------------------------" << std::endl;
    }
    delete [] zombies_array;
    return 0;
}