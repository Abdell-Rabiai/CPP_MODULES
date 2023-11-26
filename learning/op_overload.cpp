#  include <iostream>
#  include <string>
#  include <vector>

// A vector3 class that holds 3 values of float type
class Vector3 {
    public:
        float x, y, z;

    Vector3(){
        std::cout << "Vector3 constructor called" << std::endl;
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    } 
    // overloading the + operator
    Vector3 operator +(const  Vector3 &rhs) const {
        std::cout << "operator + called" << std::endl;
        Vector3 result;
        result.x = x + rhs.x;
        result.y = y + rhs.y;
        result.z = z + rhs.z;
        return result;
    }
    // overloading the prefixe increment ++ operator
    Vector3 operator ++(){
        std::cout << "++operator called" << std::endl;
        x++;
        y++;
        z++;
        return *this;
    }
     // overloading the postfix increment ++ operator
    Vector3 operator ++(int){
        std::cout << "operator++ called" << std::endl;
        Vector3 result = *this;
        x++;
        y++;
        z++;
        return result;
    }
    // overloading the == operator stream output operator
};

    bool operator ==(const Vector3 &lhs, const Vector3 &rhs) {
        return (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z);
    } 
    // overloading the extractin << operator stream output operator
    std::ostream& operator <<(std::ostream &os, const Vector3 &rhs) {
        os << "(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";
        return os;
    } 
    // overloading the insertion >> operator stream input operator
    std::istream& operator >>(std::istream &is, Vector3 &rhs) {
        is >> rhs.x >> rhs.y >> rhs.z;
        return is;
    }
int main(){
    Vector3 a;
    a.x = 1.0f;
    a.y = 2.0f;
    a.z = 3.0f;

    Vector3 b;
    b.x = 3.0f;
    b.y = 2.0f;
    b.z = 1.0f;

    // overlaoding the + operator 
    a = a + b;
    std::cout << a.x << " " << a.y << " " << a.z << std::endl;
    ++a;
    std::cout << a.x << " " << a.y << " " << a.z << std::endl;
    a++;
    std::cout << a.x << " " << a.y << " " << a.z << std::endl;
    std::cout << a << std::endl;

    std::cin >> b;
    
    std::cout << b << std::endl;
    std::cout << std::boolalpha << (a == b) << std::endl;
}