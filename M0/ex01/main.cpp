# include "Contact.hpp"
# include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string command;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): \n" << "==> ";
        std::cin >> command;
        if (command == "ADD")
            phoneBook.save_contact();
        else if (command == "SEARCH")
            phoneBook.search_contact();
        else if (command == "EXIT" || std::cin.eof()){
            std::cout << "\001\033[1;31m\002\nExiting program... \001\033[0m\002\n" << std::endl;
            return 0;
        }
        else
            std::cout << "\001\033[1;31m\002\nInvalid command. Please try again.\001\033[0m\002\n" << std::endl;
    }
}