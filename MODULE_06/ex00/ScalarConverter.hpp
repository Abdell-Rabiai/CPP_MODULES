# pragma once

# include <iostream>
# include <string>
# include <iomanip>
# include <cmath>

enum e_type
{
    CHAR, // 0
    INT, 
    FLOAT,
    DOUBLE,
};

class ScalarConverter
{
    private:
        std::string _stringToConvert;
        ScalarConverter();

    public:
        ScalarConverter(std::string stringToConvert);
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();


        const std::string &getStringToConvert() const;
        void setStringToConvert(std::string stringToConvert);

        static void convert(std::string stringToConvert);

        void convertStringToChar(); // this method is responsible for displaying the char conversion
        void convertStringToInt(); // this method is responsible for displaying the int conversion
        void convertStringToFloat(); // this method is responsible for displaying the float conversion
        void convertStringToDouble(); // this method is responsible for displaying the double conversion
};
