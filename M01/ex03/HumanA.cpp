# include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
    std::cout << "HumanA parameterized constructor called" << std::endl;
}

HumanA::~HumanA()
{
    std::cout << "HumanA destructor called" << std::endl;
}

void HumanA::attack()
{
    std::cout << this->name << " attacks with his " << this->weapon.get_type() << std::endl;
}

std::string HumanA::get_name() const
{
    return (this->name);
}
