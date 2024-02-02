# pragma once

# include <iostream>
# include <string>


// for main.cpp
template <typename Telement> void print(Telement const &elem) {
    std::cout << elem << ", ";
}

template <typename Telement> void print(Telement const &elem, bool last) {
    std::cout << elem;
    if (!last) {
        std::cout << ", ";
    }
    else {
        std::cout << std::endl;
    }
}


// The requested templeate functions
// 1. iter0 takes all args as types T
template <typename Target, typename Tlength, typename Tfunc>
void iter (Target *arr, Tlength length, Tfunc fun) {
    for (Tlength i = 0; i < length; i++) {
        (i != length - 1) ? fun(arr[i], false) : fun(arr[i], true);
    }
}


// 2. iter takes one of the args as non object type which is Tlength
// and u dont need to pass the length as a parameter of the function
template <typename Tarray, std::size_t N, typename Tfunc>
void iter0 (Tarray *arr, Tfunc fun) {
    for (size_t i = 0; i < N; i++) {
        fun(arr[i]);
    }
}

