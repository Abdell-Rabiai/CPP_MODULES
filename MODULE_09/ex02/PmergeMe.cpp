# include "PmergeMe.hpp"

int StringToInt(const std::string &str) {
    std::istringstream iss(str);
    int value;
    if (!(iss >> value)) {
        throw std::runtime_error("Invalid value");
    }
    return value;
}

// Merge-Insertion Sort for std::vector
void merge_insert(std::vector<int>& vec) {
    if (vec.size() <= 1) return;

    // Merge sort step
    std::vector<int>::iterator middle;
    middle = vec.begin() + vec.size() / 2;
    std::vector<int> left(vec.begin(), middle);
    std::vector<int> right(middle, vec.end());

    merge_insert(left);
    merge_insert(right);

    // Merge step with insertion sort
    std::merge(left.begin(), left.end(), right.begin(), right.end(), vec.begin());

    // Insertion sort step
    for (size_t i = 1; i < vec.size(); ++i) {
        int key = vec[i];
        size_t j = i;
        while (j > 0 && vec[j - 1] > key) {
            vec[j] = vec[j - 1];
            --j;
        }
        vec[j] = key;
    }
}

// Merge-Insertion Sort for std::list
void merge_insert(std::list<int>& lst) {
    if (lst.size() <= 1) return;

    // Merge sort step
    std::list<int>::iterator middle;
    middle = std::next(lst.begin(), lst.size() / 2);
    std::list<int> left(lst.begin(), middle);
    std::list<int> right(middle, lst.end());

    merge_insert(left);
    merge_insert(right);

    // Merge step with insertion sort
    lst.merge(left);
    lst.merge(right);

    // Insertion sort step
    std::list<int>::iterator it;
    for (it = ++lst.begin(); it != lst.end(); ++it) {
        std::list<int>::iterator key = it;
        std::list<int>::iterator prev = std::prev(it);
        while (it != lst.begin() && *prev > *key) {
            std::iter_swap(it, prev);
            it = prev;
            if (it != lst.begin()) prev = std::prev(it);
        }
    }
}