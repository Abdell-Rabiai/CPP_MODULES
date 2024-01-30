# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(std::string stringToConvert) : _stringToConvert(stringToConvert) {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) : _stringToConvert(other._stringToConvert) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	if (this != &other)
		this->_stringToConvert = other._stringToConvert;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

const std::string &ScalarConverter::getStringToConvert() const {
	return (this->_stringToConvert);
}

void ScalarConverter::setStringToConvert(std::string stringToConvert) {
	this->_stringToConvert = stringToConvert;
}


int detectInputType(const std::string &stringToConvert) {
	int type = 0;
	if (stringToConvert.length() == 1 && !isdigit(stringToConvert[0]))
		type = CHAR;
	else if (stringToConvert.find('.') != std::string::npos)
	{
		if (stringToConvert.find('f') != std::string::npos)
			type = FLOAT;
		else
			type = DOUBLE;
	}
	else
		type = INT;
	return (type);
}

void printConversions(const std::string &stringToConvert) {
	ScalarConverter o(stringToConvert);
	o.convertStringToChar();
	o.convertStringToInt();
	o.convertStringToFloat();
	o.convertStringToDouble();
}

void	parseForInt(const std::string &stringToConvert) {
	long res = atol(stringToConvert.c_str());
	if (res > INT_MAX || res < INT_MIN)
	{
		std::cout << "Error: Out Of Integers Range" << std::endl;
		exit(1);
	}
	for (size_t i = 0; i < stringToConvert.length(); i++)
	{
		if (i == 0 && stringToConvert[i] == '-')
			continue;
		if (!isdigit(stringToConvert[i]))
		{
			std::cout << "Error: Invalid input" << std::endl;
			exit(1);
		}
	}
}

bool onePoint(const std::string &stringToConvert) {
	int count = 0;
	for (size_t i = 0; i < stringToConvert.length(); i++)
	{
		if (stringToConvert[i] == '.')
			count++;
	}
	if (count > 1)
		return (false);
	return (true);
}

bool oneFatTheEnd(const std::string &stringToConvert) {
	if (stringToConvert[stringToConvert.length() - 1] == 'f')
		return (true);
	return (false);
}

bool oneF(const std::string &stringToConvert) {
	int count = 0;
	for (size_t i = 0; i < stringToConvert.length(); i++)
	{
		if (stringToConvert[i] == 'f')
			count++;
	}
	if (count > 1)
		return (false);
	return (true);
}

void parseForFloat(const std::string &stringToConvert) {
	for (size_t i = 0; i < stringToConvert.length(); i++)
	{
		if (i == 0 && stringToConvert[i] == '-')
			continue;
		if (!onePoint(stringToConvert) || !oneFatTheEnd(stringToConvert) || !oneF(stringToConvert)) {
			std::cout << "Error: Invalid input in float" << std::endl;
			exit(1);
		}
	}
}

bool noOtherLetter(const std::string &stringToConvert) {
	for (size_t i = 0; i < stringToConvert.length(); i++)
	{
		if (!isdigit(stringToConvert[i]) && stringToConvert[i] != '.')
			return (false);
	}
	return (true);
}

void parseForDouble(const std::string &stringToConvert) {
	for (size_t i = 0; i < stringToConvert.length(); i++)
	{
		if (i == 0 && stringToConvert[i] == '-')
			continue;
		if (!onePoint(stringToConvert) || !noOtherLetter(stringToConvert)) {
			std::cout << "Error: Invalid input in double" << std::endl;
			exit(1);
		}
	}
}

void	checkAllInfinity(const std::string &stringToConvert) {
	if (stringToConvert == "nan" || stringToConvert == "nanf"
		|| stringToConvert == "-inf" || stringToConvert == "-inff"
		|| stringToConvert == "+inf" || stringToConvert == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (stringToConvert == "nan" || stringToConvert == "nanf")
			std::cout << "float: nanf" << std::endl;
		else if (stringToConvert == "-inf" || stringToConvert == "-inff")
			std::cout << "float: -inff" << std::endl;
		else if (stringToConvert == "+inf" || stringToConvert == "+inff")
			std::cout << "float: +inff" << std::endl;
		else
			std::cout << "float: " << stringToConvert << std::endl;
		std::cout << "double: " << stringToConvert << std::endl;
		
		exit(1);
	}
}

void ScalarConverter::convert(std::string stringToConvert) {
	checkAllInfinity(stringToConvert);
	int type = detectInputType(stringToConvert);
	
	switch (type)
	{
		case CHAR: {
				printConversions(stringToConvert);
			}
			break;
		case INT: {
				parseForInt(stringToConvert);
				printConversions(stringToConvert);
			}
			break;
		case FLOAT: {
				parseForFloat(stringToConvert);
				printConversions(stringToConvert);
			}
			break;
		case DOUBLE: {
				parseForDouble(stringToConvert);
				printConversions(stringToConvert);
			}
			break;
		default:
			break;
	}
}


void ScalarConverter::convertStringToChar()
{
	std::string str = this->_stringToConvert;
	int num = std::stoi(str);
	char result = static_cast<char>(num);
	num > 32 && num < 127 ?
	 std::cout << "char: [" << result << "]" << std::endl :
	 	std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::convertStringToInt() {
	try {
		int result = 0;
		std::string str = this->_stringToConvert;
		result = static_cast<int>(std::stoi(str));
		std::cout << "int: [" << result << "]" << std::endl;
	}
	catch (const std::out_of_range &e) {
		std::cout << e.what() << std::endl;
	}
	catch (const std::invalid_argument &e) {
		std::cout << e.what() << std::endl;
	}
}

void ScalarConverter::convertStringToFloat() {
	try {
		float result = 0;
		std::string str = this->_stringToConvert;
		result = static_cast<float>(std::stof(str));
		std::cout << "float: [" << result << "f]" << std::endl;
	}
	catch (const std::out_of_range &e) {
		std::cout << e.what() << std::endl;
	}
	catch (const std::invalid_argument &e) {
		std::cout << e.what() << std::endl;
	}
}

void ScalarConverter::convertStringToDouble() {
	try {
		double result = 0;
		std::string str = this->_stringToConvert;
		result = static_cast<double>(std::stod(str));
		std::cout << "double: [" << result << "]" << std::endl;
	}
	catch (const std::out_of_range &e) {
		std::cout << e.what() << std::endl;
	}
	catch (const std::invalid_argument &e) {
		std::cout << e.what() << std::endl;
	}
}

/*
Base * generate(void);
It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
to use anything you like for the random choice implementation.
void identify(Base* p);
It prints the actual type of the object pointed to by p: "A", "B" or "C".
void identify(Base& p);
It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
inside this function is forbidden.
*/



void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base &b) {
	try {
		A &a = dynamic_cast<A&>(b);
		std::cout << "A" << std::endl;
		(void)a;
	}
	catch (std::exception &e) {
		try {
			B &a = dynamic_cast<B&>(b);
			std::cout << "B" << std::endl;
			(void)a;
		}
		catch (std::exception &e) {
			try {
				C &a = dynamic_cast<C&>(b);
				std::cout << "C" << std::endl;
				(void)a;
			}
			catch (std::exception &e) {
				std::cout << "Unknown type" << std::endl;
			}
		}
	}
}