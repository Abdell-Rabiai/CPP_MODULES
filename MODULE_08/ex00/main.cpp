# include "easyfind.hpp"

int main() {
    //test with a vector
    try {
        std::vector<int> vec;
        for (int i = 0; i < 5; i++) {
            vec.push_back(i);
        }
        int valueToFind = 3;

        int result = *easyfind(vec, valueToFind);
        std::cout << "Found: " << result << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    //test with a list
    try {
        std::list<int> lst;
        for (int i = 0; i < 5; i++) {
            lst.push_back(i);
        }
        int valueToFind = 8;

        std::list<int>::iterator result = easyfind(lst, valueToFind);
        std::cout << "Found: " << *result << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    //test with a deque
    try {
        std::deque<int> deq;
        for (int i = 0; i < 5; i++) {
            deq.push_back(i);
        }
        int valueToFind = 3;    

        int result = *easyfind(deq, valueToFind);
        std::cout << "Found: " << result << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}