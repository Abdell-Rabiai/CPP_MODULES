# include <iostream>
# include <string>


class Array
{
    private:
        int *data;

    public:
        Array()
        {
            std::cout << "default constructor called" << std::endl;
            data = new int[10];
            for (int i = 0; i < 10; i++)
                data[i] = i * i;
        }
        ~Array()
        {
            delete[] data;
        }
        // our own copy constructor
        Array(const Array &rhs)
        {
            std::cout << "copy constructor called" << std::endl;
            delete[] data;
            data = new int[10];
            for (int i = 0; i < 10; i++)
                data[i] = rhs.data[i];
        }
        // our own copy assignment operator
        Array &operator=(const Array &rhs)
        {
            std::cout << "Copy Assignement operator called\n";
            if (this == &rhs) // a = a doesn't make sense
                return (*this);
            if (data != nullptr)
                delete[] data;
            data = new int[10];
            for (int i = 0; i < 10; i++)
                data[i] = rhs.data[i];
            return *this;
        }
        void print_data()
        {
            for (int i = 0; i < 10; i++)
            std::cout << data[i] << " | ";
            std::cout << std::endl;
        }
        void set_data(int index, int value)
        {
            data[index] = value;
        }
};

int main()
{
    Array a;

    a.set_data(0, 424242);
    a.set_data(2, 1337);
    a.set_data(1, 777777);

    Array b;
    b = a; // copy assignemet operator gets called here
    // Array b = a; // copy constructor is used here to create a copy of a
    a.print_data();
    b.print_data();
    return 0;
}