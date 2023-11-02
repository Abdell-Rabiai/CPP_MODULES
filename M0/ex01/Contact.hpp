#ifndef Contact_hpp
#define Contact_hpp

#include <iostream>
#include <string>
#include <iomanip> // std::setw
#include <sstream>

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
        int id;

    public:
        Contact();
        ~Contact();
        void set_first_name(std::string first_name);
        void set_last_name(std::string last_name);
        void set_nickname(std::string nickname);
        void set_phone_number(std::string phone_number);
        void set_darkest_secret(std::string darkest_secret);
        std::string get_first_name();
        std::string get_last_name();
        std::string get_nickname();
        std::string get_phone_number();
        std::string get_darkest_secret();
        void read_contact_info();
        void print_contact_info();
        std::string check_input(std::string prompt);
};

#endif /* Contact_hpp */