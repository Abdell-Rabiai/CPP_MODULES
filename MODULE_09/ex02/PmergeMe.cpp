# include "PmergeMe.hpp"

int StringToInt(const std::string &str) {
    std::stringstream ss(str);
    int num;
    ss >> num;
    return num;
}
/* ------------------------------------for a vector---------------------------------------*/
int binarySearch(const std::vector<int>& arr, int val, int end) {
    int start = 0;
    while (start < end) {
        int mid = (start + end) / 2;
        if (arr[mid] < val) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    return start;
}

// Recursive merge-insertion sort function
void mergeInsertionSort(std::vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return;

    std::vector<int> larger, smaller;
    for (int i = 0; i < n / 2; ++i) {
        if (arr[2 * i] > arr[2 * i + 1]) {
            larger.push_back(arr[2 * i]);
            smaller.push_back(arr[2 * i + 1]);
        } else {
            larger.push_back(arr[2 * i + 1]);
            smaller.push_back(arr[2 * i]);
        }
    }

    if (n % 2 == 1) smaller.push_back(arr[n - 1]);

    mergeInsertionSort(larger);

    std::vector<int> sortedArr = larger;
    for (size_t i = 0; i < smaller.size(); ++i) {
        int pos = binarySearch(sortedArr, smaller[i], sortedArr.size());
        sortedArr.insert(sortedArr.begin() + pos, smaller[i]);
    }
    arr = sortedArr;
}

/* ------------------------------------for a list---------------------------------------*/
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
    std::list<int>::iterator end = lst.end();

    for (int i = 0; i < n / 2; ++i) {
        std::list<int>::iterator first = it;
        std::advance(first, 2 * i);
        std::list<int>::iterator second = first;
        ++second;

        if (*first > *second) {
            larger.push_back(*first);
            smaller.push_back(*second);
        } else {
            larger.push_back(*second);
            smaller.push_back(*first);
        }
    }

    if (n % 2 == 1) {
        std::list<int>::iterator last = end;
        --last;
        smaller.push_back(*last);
    }

    mergeInsertionSort(larger);

    std::list<int> sortedList = larger;
    for (std::list<int>::const_iterator sit = smaller.begin(); sit != smaller.end(); ++sit) {
        std::list<int>::iterator pos = binarySearch(sortedList, *sit);
        sortedList.insert(pos, *sit);
    }

    lst = sortedList;
}
// void mergeInsertionSort(std::list<int>& lst) {
//     int n = lst.size();
//     if (n <= 1) return;

//     std::list<int> larger, smaller;
//     std::list<int>::iterator it = lst.begin();
//     for (int i = 0; i < n / 2; ++i) {
//         if (*std::next(it, 2 * i) > *std::next(it, 2 * i + 1)) {
//             larger.push_back(*std::next(it, 2 * i));
//             smaller.push_back(*std::next(it, 2 * i + 1));
//         } else {
//             larger.push_back(*std::next(it, 2 * i + 1));
//             smaller.push_back(*std::next(it, 2 * i));
//         }
//     }

//     if (n % 2 == 1) smaller.push_back(*std::prev(lst.end()));

//     mergeInsertionSort(larger);

//     std::list<int> sortedList = larger;
//     for (std::list<int>::const_iterator sit = smaller.begin(); sit != smaller.end(); ++sit) {
//         std::list<int>::iterator pos = binarySearch(sortedList, *sit);
//         sortedList.insert(pos, *sit);
//     }

//     lst = sortedList;
// }