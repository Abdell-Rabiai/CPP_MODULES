# pragma once

# include <iostream>
# include <string>


// templeate functions

// swap : swap the values of two arguments
template <typename arg1, typename arg2> arg1 swap(arg1 &a, arg2 &b) {
    arg1 temp = a;
    a = b;
    b = temp;
    return a;
}

// max : return the maximum of two arguments
template <typename arg1, typename arg2> arg1 max(arg1 a, arg2 b) {
    return (a > b ? a : b);
}

// min : return the minimum of two arguments
template <typename arg1, typename arg2> arg1 min(arg1 a, arg2 b) {
    return (a < b ? a : b);
}

