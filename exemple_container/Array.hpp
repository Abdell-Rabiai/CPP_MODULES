# pragma once
# include <iostream>
# include <string>

template <typename myType, std::size_t N>
class Array {
    private :
        myType *myData; // m_data is of type myType* (array of elements of type myType)
        std::size_t mySize; // number of elements in the array
    public :
        // Construction with no parameter: Creates an empty array.
        // Array() {
        //     this->mySize = 0;
        //     this->myData = NULL;
        // }
        // Construction with an unsigned int n as a parameter: Creates an array of n elements initialized by default.
        Array() {
            this->mySize = N;
            this->myData = new myType[N];
            // a for loop to initialize the array with default values of type myType.
            for (size_t i = 0; i < this->mySize; i++) {
                this->myData[i] = myType();
            }
        }
        // Copy constructor 
        Array(const Array &rhs) {
            if (this != &rhs) {
                this->mySize = rhs.mySize;
                this->myData = new myType[this->mySize];
                for (size_t i = 0; i < this->mySize; i++) {
                    this->myData[i] = rhs.myData[i];
                }
            }
        }
        // Assignment
        Array &operator=(const Array &rhs) {
            if (this != &rhs) {
                delete [] this->myData; // deallocate existing memory
                this->mySize = rhs.mySize;
                this->myData = new myType[this->mySize];
                for (size_t i = 0; i < this->mySize; i++) {
                    this->myData[i] = rhs.myData[i];
                }
            }
            return *this;
        }
        // Destructor to free the memory allocated for the array.
        ~Array() {
            delete [] this->myData;
        }

        // Subscript operator  // it takes an index and returns a reference to the element at that index.
        myType &operator[](std::size_t i) {
            if (i >= this->mySize) {
                throw OutOfBoundsException();
            }
            return (this->myData[i]);
        }
        std::size_t size() const {
            return this->mySize;
        }

        void print() const {
            for (size_t i = 0; i < this->mySize; i++) {
                std::cout << this->myData[i];
                if (i < this->mySize - 1)
                    std::cout << ", ";
                else
                    std::cout << std::endl;
            }
        }

        // Exception
        class OutOfBoundsException : public std::exception {
            public :
                virtual const char *what() const throw() {
                    return "Exception Occured: OUT OF BOUNDS";
                }
        };
};