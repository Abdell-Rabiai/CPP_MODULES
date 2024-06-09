# include "Span.hpp"

int main() {
    srand(time(NULL));
    try {
        Span mySpan(5);
        mySpan.addNumber(1);
        mySpan.addNumber(2);
        mySpan.addNumber(3);
        mySpan.addNumber(4);
        mySpan.addNumber(5);
        std::cout << "Shortest span: " << mySpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << mySpan.longestSpan() << std::endl;
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    // using a range of numbers
    try {
        Span mySpan(10000);
        std::vector<int> vec;
        // make vec conatain random numbers 1 - 10000, using generate method
        for (size_t i = 1; i <= 10000; i++) {
            vec.push_back(rand());
        }
        mySpan.addRange(vec.begin(), vec.end());
        std::cout << "Shortest span: " << mySpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << mySpan.longestSpan() << std::endl;
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}