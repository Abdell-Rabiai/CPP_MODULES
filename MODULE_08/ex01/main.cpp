# include "Span.hpp"

int main() {
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
        Span mySpan(5);
        std::vector<int> vec = {1, 2, 3, 4, 5};
        mySpan.addRangeNumberS(vec.begin(), vec.end());
        std::cout << "Shortest span: " << mySpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << mySpan.longestSpan() << std::endl;
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}