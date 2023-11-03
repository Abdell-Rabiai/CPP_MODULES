#ifndef Zombie_hpp
#define Zombie_hpp

#include <iostream>
#include <string>
// #include <iomanip> // std::setw
// #include <sstream>

class Zombie
{
    private:
        std::string name;
        std::string type;

    public:
        Zombie();
        // Zombie(std::string name, std::string type);
        ~Zombie();
        void announce(void);
        void set_name(std::string name);
        void set_type(std::string type);
        std::string get_name();
        std::string get_type();
};

#endif