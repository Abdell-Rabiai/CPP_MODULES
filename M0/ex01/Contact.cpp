#include "Contact.hpp"


Contact::Contact()
{
    this->first_name = "";
    this->last_name = "";
    this->nickname = "";
    this->phone_number = "";
    this->darkest_secret = "";
}

Contact::~Contact()
{

}

void Contact::set_first_name(std::string first_name)
{
    this->first_name = first_name;
}

void Contact::set_last_name(std::string last_name)
{
    this->last_name = last_name;
}

void Contact::set_nickname(std::string nickname)
{
    this->nickname = nickname;
}

void Contact::set_phone_number(std::string phone_number)
{
    this->phone_number = phone_number;
}

void Contact::set_darkest_secret(std::string darkest_secret)
{
    this->darkest_secret = darkest_secret;
}

std::string Contact::get_first_name()
{
    return (this->first_name);
}

std::string Contact::get_last_name()
{
    return (this->last_name);
}

std::string Contact::get_nickname()
{
    return (this->nickname);
}

std::string Contact::get_phone_number()
{
    return (this->phone_number);
}

std::string Contact::get_darkest_secret()
{
    return (this->darkest_secret);
}

bool check_number(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
        {
            std::cout << "\001\033[1;31m\002\nPhone number should contain digits. Please try again.\001\033[0m\002\n" << std::endl;
            return false;
        }
    }
    return true;
}

std::string Contact::check_input(std::string prompt)
{
    std::string input = "";

    while (true)
    {
        std::cout << prompt << " ==> ";
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            std::cout << "\001\033[1;31m\002\nExiting program... EOF detected\001\033[0m\002\n" << std::endl;
            exit(0);
        }
        if (input.empty()) {
            std::cout << "\001\033[1;31m\002\nEmpty input is not allowed. Please try again.\001\033[0m\002\n" << std::endl;
            std::cin.clear();
            return (this->check_input(prompt));
        }
        else {
            if (prompt.compare("Phone number") == 0)
            {
                if (!check_number(input))
                    continue;
            }
            std::cout << "your " << prompt << " is saved as: " <<"\001\033[1;34m\002["<< input <<"]\001\033[0m\002"<< std::endl;
            break;
        }
    }
    return (input);
}

void Contact::read_contact_info()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    this->first_name = this->check_input("First name");
    this->last_name = this->check_input("Last name");
    this->nickname = this->check_input("Nickname");
    this->phone_number = this->check_input("Phone number");
    this->darkest_secret = this->check_input("Darkest secret");
    std::cout << "\001\033[1;32m\002\nContact saved successfully.\001\033[0m\002\n" << std::endl;
}

void Contact::print_contact_info()
{
    std::cout << "Contact " << this->id <<" info: " << std::endl;
    std::cout << "First name: " << this->first_name << std::endl;
    std::cout << "Last name: " << this->last_name << std::endl;
    std::cout << "Nickname: " << this->nickname << std::endl;
    std::cout << "Phone number: " << this->phone_number << std::endl;
    std::cout << "Darkest secret: " << this->darkest_secret << std::endl;
}