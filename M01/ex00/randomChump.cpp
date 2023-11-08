# include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie zombie;
    zombie.set_name(name);
    zombie.announce();
}