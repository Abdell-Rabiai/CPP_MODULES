# include "Array.hpp"

int main() {
    // test for integers 
    std::cout << "\n______Test for integers_________________________________\n" << std::endl;
    try {
        Array<int, 7> ArrayOfInts;
        std::cout << "Size of ArrayOfInts: " << ArrayOfInts.size() << std::endl;
        ArrayOfInts.print();
        ArrayOfInts[0] = 7;
        ArrayOfInts[3] = 3;
        ArrayOfInts[6] = 7;
        ArrayOfInts.print();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // test for strings
    std::cout << "\n______Test for strings_________________________________\n" << std::endl;
    try {
        Array<std::string, 3> ArrayOfStrings;
        std::cout << "Size of ArrayOfStrings: " << ArrayOfStrings.size() << std::endl;
        ArrayOfStrings.print();
        ArrayOfStrings[0] = "seven";
        ArrayOfStrings[1] = "three";
        ArrayOfStrings[2] = "seven";
        ArrayOfStrings.print();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}