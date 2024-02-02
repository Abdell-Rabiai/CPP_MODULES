# include <iostream>
# include <string>
# include <vector>
# include <algorithm>


// i' gonna implement my own version of the stl vector class in c++
// i'm gonna use templates to make it generic
// i'm gonna use dynamic memory allocation to allocate memory for the elements of the vector
// i'm gonna use the copy constructor and the assignment operator to make sure that the vector is deep copied when it's copied or assigned to another vector
// i'm gonna use the destructor to free the memory allocated for the vector when it goes out of scope
// i'm gonna use the subscript operator to access the elements of the vector
// i'm gonna use the size() method to get the size of the vector
// i'm gonna use the add() method to add an element to the end of the vector
// i'm gonna use the remove() method to remove the last element of the vector

template <typename myType> class Vector {
    private :
        myType *data; // data is of type myType* (pointer to myType) the elements of my vector will be of type myType
        std::size_t current_size; // current size of the vector
        std::size_t capacity; // capacity of the vector
    public :
        Vector() {
            data = nullptr;
            current_size = 0;
            capacity = 0;
        }
        ~Vector() {
            delete[] data;
        }
        Vector(const Vector &other) : capacity(other.capacity), current_size(other.current_size) {
            data = new myType[capacity];
            for (std::size_t i = 0; i < current_size; i++) {
                data[i] = other.data[i];
            }
        }

        Vector& operator=(const Vector &other) {
            if (this != &other) {
                delete[] data;
                capacity = other.capacity;
                current_size = other.current_size;
                data = new myType[capacity];
                for (std::size_t i = 0; i < current_size; i++) {
                    data[i] = other.data[i];
                }
            }
            return *this;
        }

        myType& operator[](std::size_t index) {
            if (index >= current_size) {
                throw std::out_of_range("Index out of range");
            }
            return data[index];
        }

        std::size_t size() const {
            return current_size;
        }

        void add(const myType &element) {
            if (current_size == capacity) {
                capacity = capacity == 0 ? 1 : capacity * 2;
                myType *new_data = new myType[capacity];
                for (std::size_t i = 0; i < current_size; i++) {
                    new_data[i] = data[i];
                }
                delete[] data;
                data = new_data;
            }
            data[current_size++] = element;
        }

        void remove() {
            if (current_size == 0) {
                throw std::out_of_range("Vector is empty");
            }
            current_size--;
        }
};

template <typename myType> std::ostream& operator<<(std::ostream &os, Vector<myType> &v) {
    for (std::size_t i = 0; i < v.size(); i++) {
        os << v[i] << " ";
    }
    return os;
}

int main()
{
    Vector<int> v;
    v.add(1);
    v.add(2);
    v.add(3);
    v.add(4);
    v.add(5);
    std::cout << v << std::endl;
    return 0;
}