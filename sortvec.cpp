#include <vector>
#include <algorithm>
#include <iostream>

void print_vector(const std::vector<int>& vec) {
    for (const auto& elem : vec) {
        std::cout <<"("<< elem << ") ";
    }
    std::cout << std::endl;
}

// Binary search to find the position to insert
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

    std::cout << "Larger:  ==> ";
    print_vector(larger);
    std::cout << "Smaller: ==> ";
    print_vector(smaller);

    mergeInsertionSort(larger);

    std::cout << "Larger after sorting: ==> ";
    print_vector(larger);

    std::vector<int> sortedArr = larger;
    for (size_t i = 0; i < smaller.size(); ++i) {
        std::cout << "Inserting " << smaller[i] << " into the sorted larger array ==> ";
        print_vector(sortedArr);
        int pos = binarySearch(sortedArr, smaller[i], sortedArr.size());
        sortedArr.insert(sortedArr.begin() + pos, smaller[i]);
        std::cout << "final sorted array ==> ";
        print_vector(sortedArr);
    }

    arr = sortedArr;
}

int main() {
    std::vector<int> vec = {78,-5,-1,0,45,3,2,1,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};

    std::cout << "Original vector: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    mergeInsertionSort(vec);
    std::cout << "After sorting :   ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    //verify it is sorted using std::is_sorted
    std::cout << "SORTED ? " << std::boolalpha << std::is_sorted(vec.begin(), vec.end()) << std::endl;
    return 0;
}
