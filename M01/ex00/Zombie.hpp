#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
// #include <iomanip> // std::setw
// #include <sstream>


class Zombie
{
    private:
        std::string name;

    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void announce(void);

        void set_name(std::string name);
        std::string get_name();
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);
#endif // ZOMBIE_HPP