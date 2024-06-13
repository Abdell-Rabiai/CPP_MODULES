# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string filename) : _filename(filename) {}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::readDataset()
{
    std::ifstream file("data.csv");
    if (!file.is_open()) {
        file.close();
        throw std::runtime_error("Error: could not open file");
    }
    std::string line;
    std::string date;
    double price;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        if (std::getline(iss, date, ',') && iss >> price) {
            this->_data[date] = price;
        }
    }
    file.close();
}

void BitcoinExchange::printData()
{
    std::map<std::string, double>::iterator it;
    for (it = this->_data.begin(); it != this->_data.end(); it++) {
        std::cout <<"{"<< it->first << "} - {" << it->second <<"}"<< std::endl;
    }
}

double StringToDouble(const std::string &str) {
    std::istringstream iss(str);
    double value;
    if (!(iss >> value)) {
        throw std::runtime_error("Invalid value");
    }
    return value;
}

int StringToInt(const std::string &str) {
    std::istringstream iss(str);
    int value;
    if (!(iss >> value)) {
        throw std::runtime_error("Invalid value");
    }
    return value;
}

bool isValidDate(const std::string &date) {
    // Check if the length of the date string is exactly 10 characters
    if (date.size() != 10) {
        return false;
    }
    // Check if the character positions where '-' should be are correct
    if (date[4] != '-' || date[7] != '-') {
        return false;
    }
    // Check if each part of the date (year, month, day) are digits
    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) {
            continue; // Skip checking '-' positions
        }
        if (!std::isdigit(date[i])) {
            return false;
        }
    }
    // Check if the year, month, and day are within the correct range
    int year = StringToInt(date.substr(0, 4));
    int month = StringToInt(date.substr(5, 2));
    int day = StringToInt(date.substr(8, 2));
    if (year < 2000 || year > 2024 || month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }
    // check for a leap year
    if (month == 2) {
        if (year % 4 == 0) {
            if (day > 29) {
                return false;
            }
        } else {
            if (day > 28) {
                return false;
            }
        }
    }
    return true;
}


// Validate value to be a float or positive integer between 0 and 1000
bool isValidValue(double value) {
    return value >= 0.0 && value <= 1000.0;
}


bool checkHeader(const std::string &line) {
    std::istringstream iss(line);
    std::string header;
    if (std::getline(iss, header, '|')) {
        header.erase(0, header.find_first_not_of(" \t\n\r\f\v"));
        header.erase(header.find_last_not_of(" \t\n\r\f\v") + 1);
        if (header != "date") {
            std::cerr << "Invalid header format0" << std::endl;
            return false;
        }
        if (std::getline(iss, header)) {
            header.erase(0, header.find_first_not_of(" \t\n\r\f\v"));
            header.erase(header.find_last_not_of(" \t\n\r\f\v") + 1);
            if (header != "value") {
                std::cerr << "Invalid header format1" << std::endl;
                return false;
            }
        } else {
            std::cerr << "Invalid header format2" << std::endl;
            return false;
        }
    } else {
        std::cerr << "Invalid header format3" << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::parseInput()
{
    std::ifstream file(this->_filename);
    if (!file.is_open()) {
        file.close();
        throw std::runtime_error("Error: could not open file");
    }
    std::string line;
    //skip the first line it should contain the header "date | value" if not invalide header format
    std::getline(file, line);
    if (!checkHeader(line))
        return ;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date;
        double bitcoin;
        if (std::getline(iss, date, '|')) {
            std::string bitcoinStr;
            if (std::getline(iss, bitcoinStr)) {
                // trim the date and bitcoinStr from both ends
                date.erase(0, date.find_first_not_of(" \t\n\r\f\v"));
                date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);
                bitcoinStr.erase(0, bitcoinStr.find_first_not_of(" \t\n\r\f\v"));
                bitcoinStr.erase(bitcoinStr.find_last_not_of(" \t\n\r\f\v") + 1);
            
               try {
                    bitcoin = StringToDouble(bitcoinStr);
                } catch (std::exception &e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                    continue;
                }
                if (isValidDate(date) && isValidValue(bitcoin)) {
                    this->_howManyBitcoin = bitcoin;
                    std::map<std::string, double>::iterator it = this->_data.lower_bound(date);
                    if (it == this->_data.end()) {
                        std::cerr << "Invalid date or value on line: " << line << std::endl;
                        continue;
                    }
                    this->_bitcoinValue = it->second;
                    std::cout << date << " => " << this->_howManyBitcoin << " = " << this->_bitcoinValue * this->_howManyBitcoin << std::endl;
                } else {
                    std::cerr << "Invalid date or value on line: " << line << std::endl;
                }
            } else {
                std::cerr << "Invalid format on line: " << line << std::endl;
            }
        
        } else {
            std::cerr << "Invalid format on line: " << line << std::endl;
        }
    }
}

void BitcoinExchange::doTheExchange()
{
    this->readDataset();
    this->parseInput();
}

// i'll add the necessary methods here