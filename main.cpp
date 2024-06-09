# include <stdio.h>
# include <string>
# include <iostream>


// write a funtio that takes a string and a charcater to fiund in it, and returns a pointer to that character
char *ft_strchr(char *s, int c) {
    while (*s) {
        if (*s == c)
            return s;
        s++;
    }
    return NULL;
}

// do the same in a c++ manner for a std::string and use iterators
std::string::iterator ft_strchr(std::string &s, int c) {
    // char *ft_strchr(std::string &s, int c) {
    std::string::iterator it = s.begin();
    // char *it = s.c_str();
    while (it != s.end()) {
        // while (*it) {
        if (*it == c)
        // if (*it == c)
            return it;
        // return it;
        it++;
        // it++;
    }
    // return NULL;
    return s.end();
}


int main() {
    // c
    char str[] = "Hello, World!";
    printf("%p\n", ft_strchr(str, 'W'));
    // cpp
    std::string s = "Hello, World!";
    std::string::iterator it = ft_strchr(s, 'W');
    printf("%p\n", &(*it));
    return 0;

}
