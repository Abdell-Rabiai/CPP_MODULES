# include "iter.hpp"

int main( void ) {

    // array of integers
    std::cout << "------Array of integers --------------------------------------" << std::endl;
    int arr[] = {1, 2, 3, 4, 5};
    size_t length = sizeof(arr) / sizeof(arr[0]);
    iter<int, size_t, void(*)(int const &, bool)>(arr, length, print<int>);
    std::cout << std::endl;

    // array of doubles
    std::cout << "------Array of doubles ---------------------------------------" << std::endl;
    double arr1[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t length1 = sizeof(arr1) / sizeof(arr1[0]);
    iter<double, size_t, void(*)(double const &, bool)>(arr1, length1, print<double>);
    std::cout << std::endl;

    // array of strings
    std::cout << "------Array of strings ---------------------------------------" << std::endl;
    std::string arr2[] = {"one", "two", "three", "four", "five"};
    size_t length2 = sizeof(arr2) / sizeof(arr2[0]);
    iter<std::string, size_t, void(*)(std::string const &, bool)>(arr2, length2, print<std::string>);
    std::cout << std::endl;

    // array of chars
    std::cout << "------Array of chars -----------------------------------------" << std::endl;
    char arr3[] = {'a', 'b', 'c', 'd', 'e'};
    size_t length3 = sizeof(arr3) / sizeof(arr3[0]);
    iter<char, size_t, void(*)(char const &, bool)>(arr3, length3, print<char>);
    std::cout << std::endl;
    return 0;
}