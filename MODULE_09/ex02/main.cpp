# include "PmergeMe.hpp"

double sort_vector(std::vector<int>& numbers) {
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end_vec;
    start = std::chrono::high_resolution_clock::now();
    merge_insert(numbers);
    end_vec = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration_vec = end_vec - start;
    return duration_vec.count();
}

double sort_list(std::list<int>& lst) {
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
    start = std::chrono::high_resolution_clock::now();
    merge_insert(lst);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration_list = end - start;
    return duration_list.count();
}

void print_timing(double duration_vec, double duration_list, int list_size) {
    std::cout << "Time to process a range of " << list_size << " elements with std::vector: "
              << duration_vec << " ms" << std::endl;
    std::cout << "Time to process a range of " << list_size << " elements with std::list: "
              << duration_list << " ms" << std::endl;
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
    std::cout << "After: ";
    print_container(numbers);

    // Display the timing results
    print_timing(duration_vec, duration_list, numbers.size());

    return 0;
}
