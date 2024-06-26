# include "PmergeMe.hpp"

double sort_vector(std::vector<int>& numbers) {
    clock_t start, end;
    start = clock();
    mergeInsertionSort(numbers);
    end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC * 1000000.0; // Convert to microseconds
    // in milliseconds CLOCKS_PER_SEC * 1000.0; // Convert to milliseconds
}

double sort_list(std::list<int>& lst) {
    clock_t start, end;
    start = clock();
    mergeInsertionSort(lst);
    end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC * 1000000.0; // Convert to milliseconds
}

void print_timing(double duration_vec, double duration_list, int list_size) {
    std::cout << "Time to process a range of " << list_size << " elements with std::vector: "
              << duration_vec << " us" << std::endl;
    std::cout << "Time to process a range of " << list_size << " elements with std::list: "
              << duration_list << " us" << std::endl;
}

std::vector<int> parseSequence(int argc, char* argv[]) {
    std::vector<int> numbers;
    try {
        for (int i = 1; i < argc; i++) {
            int num = StringToInt(argv[i]);
            if (num < 0)
                throw std::invalid_argument("Negative numbers are not allowed");
            numbers.push_back(num);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(1);
    }
    return numbers;
} 

int main(int argc, char* argv[]) {

    std::vector<int> numbers = parseSequence(argc, argv);
    std::cout << "Before: ";
    print_container(numbers);

    // Copy numbers to list
    std::list<int> mylist(numbers.begin(), numbers.end());

    double duration_vec = sort_vector(numbers);
    double duration_list = sort_list(mylist);
    // Display the sorted sequence
    std::cout << "vector : After: ";
    print_container(numbers);
    std::cout << "list : After  : ";
    print_container(mylist);

    // Display the timing results
    print_timing(duration_vec, duration_list, numbers.size());


    // std::cout << std::boolalpha << "Is the vector sorted? " << std::is_sorted(numbers.begin(), numbers.end()) << std::endl;
    // std::cout << "Is the list sorted? " << std::is_sorted(mylist.begin(), mylist.end()) << std::endl;
    return 0;
}
