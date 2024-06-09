# pragma once
# include <iostream>
# include <map>
# include <fstream>
# include <sstream>
# include <string>
# include <exception>
# include <vector>
# include <regex>
class BitcoinExchange
{
    private:
        std::string _filename; // filename of the dataset
        double _howManyBitcoin; // how many bitcoin the user wants to exchange
        double _bitcoinValue; // bitcoin value in USD
        std::map<std::string, double> _data; // <date, price> from the dataset
        // <date, bitcoin_value> is the result of the exchange rate of bitcoin to USD
        // the bitcoin_value is a string in that format: "1 BTC = 12345.67 $"

    public:
        BitcoinExchange();
        BitcoinExchange(std::string filename);
        ~BitcoinExchange();

        void readDataset();
        void parseInput();
        void doTheExchange();
        void printData();
        void calculateBitcoinValue();

};
