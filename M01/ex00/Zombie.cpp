#include "Zombie.hpp"


Zombie::Zombie()
{
    std::cout << "Zombie constructor called" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
Zombie::Zombie(std::string name)
{
    std::cout << "Zombie constructor called" << name << "is born" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie destructor called " << this->name << " is dead" << std::endl;
}

void Zombie::set_name(std::string name)
{
    this->name = name;
}

std::string Zombie::get_name()
{
    return this->name;
}
