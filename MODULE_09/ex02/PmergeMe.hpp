# pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <chrono>
#include <stdexcept>

template <typename T>
void print_container(const T& container) {
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void merge_insert(std::vector<int>& vec);
void merge_insert(std::list<int>& lst);
int StringToInt(const std::string &str);
std::vector<int> parseSequence(int argc, char* argv[]);