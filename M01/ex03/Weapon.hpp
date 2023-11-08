#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <string>


class Weapon
{
    private:
        std::string	type;
          
    public:
        Weapon(); // default constructor
        Weapon(std::string type); // parameterized constructor
        ~Weapon(); // destructor
        std::string get_type();
        void set_type(std::string type);    
};

#endif // WEAPON_HPP