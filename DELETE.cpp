#include <iostream>
#include <string>

class Contact {
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

public:
    Contact() : first_name(""), last_name(""), nickname(""), phone_number(""), darkest_secret("") {}

    void inputContactInfo() {
        std::cout << "Enter First Name: ";
        std::cin >> first_name;
        std::cout << "Enter Last Name: ";
        std::cin >> last_name;
        std::cout << "Enter Nickname: ";
        std::cin >> nickname;
        std::cout << "Enter Phone Number: ";
        std::cin >> phone_number;
        std::cin.ignore(); // Clear the newline character from the buffer
        std::cout << "Enter Darkest Secret: ";
        std::getline(std::cin, darkest_secret);
    }

    void displayContactInfo() {
        std::cout << "First Name: " << first_name << std::endl;
        std::cout << "Last Name: " << last_name << std::endl;
        std::cout << "Nickname: " << nickname << std::endl;
        std::cout << "Phone Number: " << phone_number << std::endl;
        std::cout << "Darkest Secret: " << darkest_secret << std::endl;
    }
};

class PhoneBook {
private:
    Contact contacts[8];
    int contactCount;

public:
    PhoneBook() : contactCount(0) {}

    void addContact() {
        if (contactCount < 8) {
            contacts[contactCount].inputContactInfo();
            contactCount++;
        } else {
            // Replace the oldest contact with the new one
            for (int i = 0; i < 7; i++) {
                contacts[i] = contacts[i + 1];
            }
            contacts[7].inputContactInfo();
        }
    }

    void searchContact() {
        if (contactCount == 0) {
            std::cout << "PhoneBook is empty." << std::endl;
            return;
        }

        // Display contacts in a tabular format
        std::cout << "Index    | First Name | Last Name  | Nickname  " << std::endl;
        for (int i = 0; i < contactCount; i++) {
            std::cout << i << "        | ";
            std::cout << std::setw(10) << std::right << contacts[i].getFirstName() << " | ";
            std::cout << std::setw(10) << std::right << contacts[i].getLastName() << " | ";
            std::cout << std::setw(10) << std::right << contacts[i].getNickname() << std::endl;
        }

        int index;
        std::cout << "Enter the index of the contact you want to view: ";
        std::cin >> index;

        if (index >= 0 && index < contactCount) {
            contacts[index].displayContactInfo();
        } else {
            std::cout << "Invalid index." << std::endl;
        }
    }
};

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::cin >> command;

        if (command == "ADD") {
            phoneBook.addContact();
        } else if (command == "SEARCH") {
            phoneBook.searchContact();
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }

    return 0;
}
