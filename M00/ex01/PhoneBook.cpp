#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->num_of_contacts = 0;
}

PhoneBook::~PhoneBook()
{

}

void PhoneBook::save_contact()
{
    static int i = 0;
    if (this->num_of_contacts < 8)
    {
        this->contacts[this->num_of_contacts].read_contact_info();
        this->num_of_contacts++;
        i = this->num_of_contacts;
    }
    else
    {
        std::cout << "Phonebook is full, replacing the oldest contact..." << std::endl;
        this->contacts[i % 8].read_contact_info();
        i++;
    }
}

std::string PhoneBook::truncate_string(std::string str)
{
    std::string truncated_str;
    if (str.length() > 10)
    {
        truncated_str = str.substr(0, 9);
        truncated_str += ".";
    }
    else
        truncated_str = str;
    return (truncated_str);
}

int PhoneBook::display_all_contacts()
{
    if (this->num_of_contacts == 0)
    {
        std::cout << "\001\033[1;36m\002\nNo contacts saved yet.\001\033[0m\002\n" << std::endl;
        return 0;
    }
    std::cout << "\001\033[1;36m\002-----------------------\001\033[0m\002 \001\033[1;33m\002MY PHONE BOOK\001\033[0m\002 \001\033[1;36m\002--------------------------------\001\033[0m\002" << std::endl;
    for (int i = 0; i < this->num_of_contacts; i++)
    {
        std::cout << "id" << "\001\033[1;34m\002" << std::setw(10) << i << "\001\033[0m\002" << "\001\033[1;36m\002|\001\033[0m\002";
        std::cout << "\001\033[1;34m\002" << std::setw(10) << this->truncate_string(this->contacts[i].get_first_name()) << "\001\033[0m\002" << "\001\033[1;36m\002|\001\033[0m\002";
        std::cout << "\001\033[1;34m\002" << std::setw(10) << this->truncate_string(this->contacts[i].get_last_name()) << "\001\033[0m\002" << "\001\033[1;36m\002|\001\033[0m\002";
        std::cout << "\001\033[1;34m\002" << std::setw(10) << this->truncate_string(this->contacts[i].get_nickname()) << "\001\033[0m\002" << "\001\033[1;36m\002|\001\033[0m\002";
        std::cout << std::endl;
        std::cout << "\001\033[1;36m\002----------------------------------------------------------------------\001\033[0m\002" << std::endl;
    }
    return 1;
}

void PhoneBook::search_contact_by_index(int index)
{
    std::cout << "First name: " << this->contacts[index].get_first_name() << std::endl;
    std::cout << "Last name: " << this->contacts[index].get_last_name() << std::endl;
    std::cout << "Nickname: " << this->contacts[index].get_nickname() << std::endl;
    std::cout << "Phone number: " << this->contacts[index].get_phone_number() << std::endl;
    std::cout << "Darkest secret: " << this->contacts[index].get_darkest_secret() << std::endl;
}

void PhoneBook::search_contact()
{
    int index;
    // display saved contacts
    if (!this->display_all_contacts())
        return ;
    // display specific contact info by index
    std::cout << "Enter an index to search for: ";
    std::cin >> index;
    if (std::cin.eof())
    {
        std::cout << "\001\033[1;31m\002\nEOF detected, exiting...\001\033[0m\002\n" << std::endl;
        exit(0);
    }
    if (std::cin.good())
    {
        if (index >= 0 && index < this->num_of_contacts)
            this->search_contact_by_index(index);
        else 
            std::cout << "\001\033[1;31m\002\nInvalid index, Out Of Range\001\033[0m\002\n" << std::endl;
    }
    else
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\001\033[1;31m\002\nInvalid index, Please provide me an integer\001\033[0m\002\n" << std::endl;
        this->search_contact();
    }
}

