// This example illustrates overloading the plus (+) operator.

#include <iostream>
using namespace std;

class complx
{
    public:
        double real, imag;
    public:
        complx( double real = 0., double imag = 0.); // constructor
        complx operator+(const complx &) const;       // operator+()
};

// define constructor
complx::complx( double r, double i )
{
      real = r; imag = i;
}

// define overloaded + (plus) operator
complx complx::operator+ (const complx& c) const
{
      complx result;
      result.real = (this->real + c.real);
      result.imag = (this->imag + c.imag);
      return result;
}

int main()
{
      complx x(4,4);
      cout << "x = " << x.real << " + " << x.imag << "i" << endl;
      complx y(6,6);
      cout << "y = " << y.real << " + " << y.imag << "i" << endl;
      complx z = x + y; // calls complx::operator+()
     cout << "z = " << z.real << " + " << z.imag << "i" << endl;
}