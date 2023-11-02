#ifndef PhoneBook_hpp
#define PhoneBook_hpp

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int num_of_contacts;

    public:
        PhoneBook();
        ~PhoneBook();
        void save_contact();
        void search_contact();
        int display_all_contacts();
        void search_contact_by_index(int index);
        std::string truncate_string(std::string str);
        bool check_number(std::string str);
};

#endif /* PhoneBook_hpp */