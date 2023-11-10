# include <iostream>
# include <string>


class Array
{
    private:
        int *data;

    public:
        Array(){
             data = new int[10];
            for (int i = 0; i < 10; i++)
                data[i] = i * i;
        }
        ~Array(){
            delete[] data;
        }

        void print_data(){
            for (int i = 0; i < 10; i++)
                std::cout << data[i] << " | ";
            std::cout << std::endl;
        }

        void set_data(int index, int value){
            data[index] = value;
        }
};

int main()
{
    Array a;
    Array b = a;

    a.set_data(0, 424242);
    a.set_data(2, 1337);
    a.set_data(1, 777777);

    // copy constructor is used here to create a copy of a
    a.print_data();
    b.print_data();
    return 0;
}