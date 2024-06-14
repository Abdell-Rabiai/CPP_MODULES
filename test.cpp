#include <list>
#include <iostream>

// Helper function to perform binary search and return insertion point
std::list<int>::iterator binarySearch(std::list<int>& lst, int value) {
    std::list<int>::iterator it = lst.begin();
    while (it != lst.end() && *it < value) {
        ++it;
    }
    return it;
}

// Function to merge two sorted lists into one sorted list
void merge(std::list<int>& larger, std::list<int>& smaller, std::list<int>& merged) {
    while (!larger.empty() && !smaller.empty()) {
        if (larger.front() < smaller.front()) {
            merged.push_back(larger.front());
            larger.pop_front();
        } else {
            merged.push_back(smaller.front());
            smaller.pop_front();
        }
    }
    // Append remaining elements (if any)
    while (!larger.empty()) {
        merged.push_back(larger.front());
        larger.pop_front();
    }
    while (!smaller.empty()) {
        merged.push_back(smaller.front());
        smaller.pop_front();
    }
}

// Recursive merge-insertion sort function for std::list
void mergeInsertionSort(std::list<int>& lst) {
    int n = lst.size();
    if (n <= 1) return;

    std::list<int> larger, smaller;

    // Partition into larger and smaller lists
    std::list<int>::iterator it = lst.begin();
    for (int i = 0; i < n / 2; ++i) {
        std::list<int>::iterator next_it = it;
        std::advance(next_it, 1);
        if (*it > *next_it) {
            larger.push_back(*it);
            smaller.push_back(*next_it);
        } else {
            larger.push_back(*next_it);
            smaller.push_back(*it);
        }
        std::advance(it, 2); // Move to the next pair
    }

    if (n % 2 == 1) {
        std::list<int>::iterator last_it = lst.end();
        --last_it;
        smaller.push_back(*last_it);
    }

    // Recursively sort larger list
    mergeInsertionSort(larger);

    // Merge sorted smaller list into sorted larger list
    std::list<int> sortedList;
    merge(larger, smaller, sortedList);

    // Assign sortedList to original list
    lst = sortedList;
}

int main() {
    std::list<int> lst = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    std::cout << "Original list: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    mergeInsertionSort(lst);

    std::cout << "Sorted list using merge-insertion sort: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
