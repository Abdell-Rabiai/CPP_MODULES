# include "HumanA.hpp"
# include "HumanB.hpp"
# include "Weapon.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.set_type("some other type of club");
        bob.attack();
    }
    std::cout << "\n---------------------\n" << std::endl;
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.set_weapon(&club);
        jim.attack();
        club.set_type("some other type of club");
        jim.attack();
    }
    return (0);
}