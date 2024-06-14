#include <iostream>
#include <list>

// Function to print elements of a list
void print_list(const std::list<int>& lst) {
    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// Binary search to find the position to insert in a sorted list
std::list<int>::iterator binarySearch(std::list<int>& lst, int val) {
    std::list<int>::iterator it = lst.begin();
    while (it != lst.end() && *it < val) {
        ++it;
    }
    return it;
}

// Recursive merge-insertion sort function for std::list
void mergeInsertionSort(std::list<int>& lst) {
    int n = lst.size();
    if (n <= 1) return;

    std::list<int> larger, smaller;
    std::list<int>::iterator it = lst.begin();
    for (int i = 0; i < n / 2; ++i) {
        if (*std::next(it, 2 * i) > *std::next(it, 2 * i + 1)) {
            larger.push_back(*std::next(it, 2 * i));
            smaller.push_back(*std::next(it, 2 * i + 1));
        } else {
            larger.push_back(*std::next(it, 2 * i + 1));
            smaller.push_back(*std::next(it, 2 * i));
        }
    }

    if (n % 2 == 1) smaller.push_back(*std::prev(lst.end()));

    mergeInsertionSort(larger);

    std::list<int> sortedList = larger;
    for (std::list<int>::const_iterator sit = smaller.begin(); sit != smaller.end(); ++sit) {
        std::list<int>::iterator pos = binarySearch(sortedList, *sit);
        sortedList.insert(pos, *sit);
    }

    lst = sortedList;
}

int main() {
    std::list<int> lst = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    std::cout << "Original list: ";
    print_list(lst);

    mergeInsertionSort(lst);

    std::cout << "After sorting: ";
    print_list(lst);

    return 0;
}
