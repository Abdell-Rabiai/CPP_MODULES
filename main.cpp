#include <iostream>
#include <vector>

// Function to sort pairs
void sort_pairs(std::vector<int>& vec) {
    for (size_t i = 0; i + 1 < vec.size(); i += 2) {
        if (vec[i] > vec[i + 1]) {
            std::swap(vec[i], vec[i + 1]);
        }
    }
}

void print_vector(const std::vector<int>& vec) {
    for (const int& num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void merge_vectors(std::vector<int>& vec, size_t left, size_t middle, size_t right) {
    std::vector<int> left_vec(vec.begin() + left, vec.begin() + middle + 1);
    std::vector<int> right_vec(vec.begin() + middle + 1, vec.begin() + right + 1);

    size_t i = 0, j = 0, k = left;
    while (i < left_vec.size() && j < right_vec.size()) {
        if (left_vec[i] <= right_vec[j]) {
            vec[k] = left_vec[i];
            ++i;
        } else {
            vec[k] = right_vec[j];
            ++j;
        }
        ++k;
    }

    while (i < left_vec.size()) {
        vec[k] = left_vec[i];
        ++i;
        ++k;
    }

    while (j < right_vec.size()) {
        vec[k] = right_vec[j];
        ++j;
        ++k;
    }
}

void merge_sort_recursive(std::vector<int>& vec, size_t left, size_t right) {
    if (left < right) {
        size_t middle = left + (right - left) / 2;

        merge_sort_recursive(vec, left, middle);
        merge_sort_recursive(vec, middle + 1, right);

        merge_vectors(vec, left, middle, right);
    }
}


int main() {
    std::vector<int> vec = {4, 1, 3, 2, 7, 6, 5};

    std::cout << "Original vector: ";
    print_vector(vec);
    sort_pairs(vec);
    std::cout << "After sorting pairs: ";
    print_vector(vec);

    // sort the pairs
    merge_sort_recursive(vec, 0, vec.size() - 1);
    print_vector(vec);

    return 0;
}
