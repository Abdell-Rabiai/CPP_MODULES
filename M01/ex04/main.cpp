# include "ex4.hpp"

void read_and_replace(std::ifstream &inputf, std::ofstream &outputf, std::string &s1, std::string &s2)
{
    std::string line = "";
    while (std::getline(inputf, line))
    {
        while (line.find(s1) != std::string::npos)
            line.replace(line.find(s1), s1.length(), s2);
        outputf << line << std::endl;
    }
}

bool parse_arguments(int ac, char **av, std::string &filename, std::string &string1, std::string &string2) {
    if (ac != 4) {
        std::cout << "Invalid number of arguments" << std::endl;
        return false;
    }
    filename = av[1];
    string1 = av[2];
    string2 = av[3];
    return true;
}

bool create_files(std::string filename, std::string new_filename, std::ifstream &inputf, std::ofstream &outputf) {
    inputf.open(filename, std::ios::in);
    if (!inputf.is_open()) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return false;
    }
    outputf.open(new_filename, std::ios::out);
    if (!outputf.is_open()) {
        std::cerr << "Error: Unable to open output file." << std::endl;
        return false;
    }
    return true;
}

int main(int ac, char **av) {

    std::string new_filename;
    std::string filename;
    std::string string1;
    std::string string2;

    if (!parse_arguments(ac, av, filename, string1, string2))
        return 1;
    new_filename = filename + ".replace";
    std::ifstream input_file;
    std::ofstream output_file;
    if (!create_files(filename, new_filename, input_file, output_file))
        return 1;
    read_and_replace(input_file, output_file, string1, string2);
    return 0;
}