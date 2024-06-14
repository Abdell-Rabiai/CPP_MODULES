# pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <chrono>
#include <stdexcept>

// Print the container
template <typename T>
void print_container(const T& container) {
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
// Binary search to find the position to insert
int binarySearch(const std::vector<int>& arr, int val, int end);
int binarySearch(const std::list<int>& lst, int val, int end);
int StringToInt(const std::string &str);
void mergeInsertionSort(std::vector<int>& arr);
void mergeInsertionSort(std::list<int>& lst);
std::vector<int> parseSequence(int argc, char* argv[]);