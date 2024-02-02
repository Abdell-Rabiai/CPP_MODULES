# include <iostream>
# include <string>
# include <vector>
# include <algorithm>

// int
int square(int x) {
    return (x * x);
}

// float
float square(float x) {
    return (x * x);
}

// double
double square(double x) {
    return (x * x);
}

// char
char square(char x) {
    return x * x;
}

// std::string
std::string square(std::string x) {
    std::string result;
    for (int i = 0; i < x.size(); i++) {
        result += x[i] * x[i];
    }
    return (result);
}

// std::vector
std::vector<int> square(std::vector<int> x) {
    std::vector<int> result;
    for (int i = 0; i < x.size(); i++) {
        result.push_back(x[i] * x[i]);
    }
    return (result);
}

// matrix vector<vector<int>>
std::vector<std::vector<int> > square(std::vector<std::vector<int> > x) {
    std::vector<std::vector<int> > result;
    for (int i = 0; i < x.size(); i++) {
        std::vector<int> row;
        for (int j = 0; j < x[i].size(); j++) {
            row.push_back(x[i][j] * x[i][j]);
        }
        result.push_back(row);
    }
    return (result);
}

// Templates are a way to write a single function that can work with many different types of data.
// The compiler will generate a new version of the function for each type of data it is used with.
// This is called "implicit instantiation".
// they're called generics in java
// they serve as a blueprint for the compiler to generate code for a function or class

template <typename myType> myType square(myType x) {
    return (x * x);
}

// overload the insertion operator for vector
std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "[";
    for (int i = 0; i < v.size(); i++) {
        os << v[i];
        if (i != v.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return (os);

}

// this auto version is the same as the template version
// auto square(auto x) {
//     return (x * x);
// }
//
// 1. The template keyword is used to declare a template.
// 2. The <typename T> syntax is used to declare a template parameter list.
// 3. The T is a placeholder for the type that will be passed as an argument to the function.
// 4. The T is used as the type of the function parameter and the return type of the function.
// 5. The function is defined as a normal function, but with the template parameter list included.
// 7. The compiler will generate a new version of the function for each type of data it is used with.
// 8. This is called "implicit instantiation".
// template instantiation is the process of generating a new version of a function or class for each type of data it is used with.


template <typename arg1, typename arg2> arg1 swap(arg1 a, arg2 b) {
    arg1 temp = a;
    a = b;
    b = temp;
    return a;
}

template <typename arg1, typename arg2> arg1 max(arg1 a, arg2 b) {
    return (a > b ? a : b);
}

template <typename arg1, typename arg2> arg1 min(arg1 a, arg2 b) {
    return (a < b ? a : b);
}



int main() {
    std::cout << square(4) << std::endl;
    // we can excplitly tell the compiler what type we want to use
    std::cout << square<int>(4) << std::endl;
    std::cout << square<float>(4.5f) << std::endl;
    std::cout << square<double>(4.5) << std::endl;

    std::cout << square('\n') << std::endl;
    std::cout << square(std::string("hello")) << std::endl;

    std::vector<int> v = {1, 2, 3, 4, 5};
    std::vector<int> result = square(v);
    std::cout << result << std::endl;
    
    return 0;
}