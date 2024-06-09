# include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	try {
		if (ac != 2) {
			std::cout << "Error: could not open file" << std::endl;
			return (0);
		}

		std::string filename(av[1]); 
		BitcoinExchange ex(filename);
		ex.doTheExchange();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}