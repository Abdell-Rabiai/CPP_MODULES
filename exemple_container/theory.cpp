// I.TEMPLATES or (Genrics) : are some of the powerful methods in c++, allwoing us to write generic code.
// it allows us to define generic functions and classes, which can work with any data type

// which allows the programmer to write the same function or class to work with different
// parameters without having to rewrite the code for each type.

// we can define a tempalete as a blueprint or formula for creating a generic classs or functions.
// the library containers like vector, stack, queue, list, map, etc. are implemented using templates.
// we can also create our own templates by passing the data type as a parameter.

// we use them for
// ---> generic programming
// ---> aviod code duplication (copy paste code)
// ---> to create a class or function that can work with any data type.
// ---> serve as a blueprint for creating a class or function. (Efficient code)

// syntax:
//template <class T> or 
# include <iostream>

template <typename T>
class Container {
    // Assuming Container is an abstract base class
    // with virtual functions that Vectorr will override.
public:
    virtual void add(const T& element) = 0;
    virtual T get(int index) const = 0;
    virtual T& operator[](int index) = 0;
    virtual const T& operator[](int index) const = 0;
    virtual int size() const = 0;
};

template <typename T>
class Vectorr : public Container <T>
{
    private :
        T* data;
        int count;
        int capacity;

        void resize() {
            capacity *= 2;
            T *temp = new T[capacity];
            for (int i = 0; i < count; i++)
                temp[i] = data[i];
            delete [] data;
            data = temp;
        }

    public :
        Vectorr() : count(0), capacity(10) {
            data = new T[capacity];
        }
        ~Vectorr() {
            delete [] data;
        }
        
        void add(const T& element) override {
            if (count == capacity)
                this->resize();
            data[count] = element;
            count++;
        }

        T get(int index) const override {
            return data[index];
        }

        T& operator[](int index) override {
            if (index < 0 || index >= count)
                throw std::out_of_range("Index out of range");
            return data[index];
        }

        const T& operator[](int index) const override {
            if (index < 0 || index >= count)
                throw std::out_of_range("Index out of range");
            return data[index];
        }

        int size() const override {
            return count;
        }

        void print() {
            for (int i = 0; i < count; i++)
                std::cout << data[i] << " | ";
            std::cout << std::endl;
        }
};


int main()
{
    Vectorr<int> intVec;
    Vectorr<std::string> stringVec;

    intVec.add(1);
    intVec.add(2);
    intVec.add(3);
    intVec.print();

    std::cout << "Size of intVec: " << intVec.size() << std::endl;
    std::cout << "--------------------\n";

    stringVec.add("Hello");
    stringVec.add("World");
    stringVec.add("!");
    stringVec.print();

    std::cout << "Size of stringVec: " << stringVec.size() << std::endl;
}
