# include "Array.hpp"

int main() {
    // test for integers
    std::cout << "\n______Test for integers_________________________________\n" << std::endl;
    try {
        Array<int, 7> ArrayOfInts(7);
        std::cout << "Size of ArrayOfInts: " << ArrayOfInts.size() << std::endl;
        ArrayOfInts.print();
        ArrayOfInts[0] = 7;
        ArrayOfInts[3] = 3;
        ArrayOfInts[6] = 7;
        ArrayOfInts.print();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }


    // test for doubles
    std::cout << "\n______Test for doubles_________________________________\n" << std::endl;
    try {
        Array<double, 5> ArrayOfDoubles(5);
        std::cout << "Size of ArrayOfDoubles: " << ArrayOfDoubles.size() << std::endl;
        ArrayOfDoubles.print();
        ArrayOfDoubles[0] = 7.7;
        ArrayOfDoubles[3] = 3.3;
        ArrayOfDoubles[4] = 7.7;
        ArrayOfDoubles.print();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // test for strings
    std::cout << "\n______Test for strings_________________________________\n" << std::endl;
    try {
        Array<std::string, 3> ArrayOfStrings(7);
        std::cout << "Size of ArrayOfStrings: " << ArrayOfStrings.size() << std::endl;
        ArrayOfStrings.print();
        ArrayOfStrings[0] = "seven";
        ArrayOfStrings[1] = "three";
        ArrayOfStrings[2] = "seven";
        ArrayOfStrings.print();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // test for charachters
    std::cout << "\n______Test for charachters_______________________________\n" << std::endl;
    try {
        Array<char, 5> ArrayOfChars(5);
        std::cout << "Size of ArrayOfChars: " << ArrayOfChars.size() << std::endl;
        ArrayOfChars.print();
        ArrayOfChars[0] = 'A';
        ArrayOfChars[3] = 'B';
        ArrayOfChars[4] = 'C';
        ArrayOfChars.print();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n______Test for copy constructor and assignment operator___\n" << std::endl;
    // test for copy constructor
    try {
        Array<int, 7> ArrayOfInts(7);
        ArrayOfInts[0] = 7;
        ArrayOfInts[3] = 3;
        ArrayOfInts[6] = 7;
        std::cout << "Size of ArrayOfInts: " << ArrayOfInts.size() << std::endl;
        ArrayOfInts.print();
        std::cout << "creating a copy of ArrayOfInts" << std::endl;
        Array<int, 7> ArrayOfIntsCopy(ArrayOfInts);
        std::cout << "Size of ArrayOfIntsCopy: " << ArrayOfIntsCopy.size() << std::endl;
        ArrayOfIntsCopy.print();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n______Test for assignment operator_______________________\n" << std::endl;
    // test for assignment operator
    try {
        Array<int, 7> ArrayOfInts(7);
        ArrayOfInts[0] = 7;
        ArrayOfInts[3] = 3;
        ArrayOfInts[6] = 7;
        std::cout << "Size of ArrayOfInts: " << ArrayOfInts.size() << std::endl;
        ArrayOfInts.print();
        std::cout << "creating a copy of ArrayOfInts" << std::endl;
        Array<int, 7> ArrayOfIntsCopy(3); // ArrayOfIntsCopy is smaller than ArrayOfInts
        ArrayOfIntsCopy = ArrayOfInts; // ArrayOfIntsCopy is assigned to ArrayOfInts same size, same data
        std::cout << "Size of ArrayOfIntsCopy: " << ArrayOfIntsCopy.size() << std::endl;
        ArrayOfIntsCopy.print();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}