# include "Harl.hpp"

int main(void)
{
    std::cout << "Hello, welcome to the Harl's world!" << std::endl;
    Harl harl;
    std::cout << "Please enter a level of complain (debug, info, warning, error): \n";
    while (true)
    {
        std::cout << ">> ";
        std::string level;
        std::cin >> level;
        if (level == "EXIT" || std::cin.eof()){
            std::cin.ignore();
            std::cin.clear();
            std::cout << "Exiting ...!" << std::endl;
            exit(0) ;
        }
        harl.complain(level);
    }
}