# include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon &weapon; // reference to a Weapon object (composition)
    
    public:
     
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
        void attack();
        std::string get_name() const;
};