# include <iomanip> 
# include <iostream>
# include <string>
# include <cmath>
# include <utility>


int main()
{
    // implicit conversion
    // exempl 1:
    // std::cout << std::fixed << std::setprecision(1) << (float)7/5 << std::endl;

    // exempl 2:
    // int res = 99997777;
    // short c = res;
    // std::cout << c << std::endl;

    // the three lines above are the same as the line below
    // std::cout << (short)res << std::endl;

    // std::cout << "size of res: " << sizeof(res) << std::endl;
    // std::cout << "size of c: " << sizeof(c) << std::endl;

    // exempl 3:
    // unsigned int b = -42;
    // int a = 42;
    // if (a < b) {
    //     std::cout << "CORRECT" << std::endl;
    // }

    // exempl 4: floatin point literals | double literals | long double literals
    // auto pi = 3.141526; // the compiler will decide the type of pi and its double 

    // exempl 5: static cast on primitive types
    // cast a float to an int
    float f = 3.14f;
    int i = static_cast<int>(f);
    std::cout << i << std::endl;

    return 0;
}
