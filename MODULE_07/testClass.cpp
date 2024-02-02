# include <iostream>
# include <string>


template <typename myType, std::size_t N>
class Container {
    private :
        myType *m_data; // m_data is of type myType* (pointer to myType)
    public :
        Container() {
            m_data = new myType[N];
        }
        ~Container() {
            delete [] m_data;
        }
    static myType var;
};

// for the satatic member variable, no matter how many objects of the class are created, there is only one copy of the static member variable.
// and it is shared by all the objects instantiated from the class.

// The static member variable must be defined outside the class, in the global scope.

template <typename myType, std::size_t N>myType Container<myType, N>::var;

int main() {
    Container<int, 7> c;
    Container<int, 8> c1;
    Container<int, 7>::var = 1337;
    Container<int, 8>::var = 1338;
    std::cout << Container<int, 7>::var << std::endl;
    std::cout << Container<int, 8>::var << std::endl;
    return 0;
}