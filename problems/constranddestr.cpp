#include <iostream>
#include <cstring>
using namespace std;

class DynamicArray
{
    private:
        char *arr;
        int length;

        void copy(const char *_arr)
        {
            this.length = 0;
            if (this->arr != nullptr)
            {
                delete[] this->arr;
                this->arr = nullptr;
            }

            if (_arr != nullptr && strlen(_arr) > 0)
            {
                this->length = strlen(_arr);
                this->arr = new char[this->length + 1];
                strcpy(this->arr, _arr);
            }
            
        }
    public:
        DynamicArray()
        {
            this->arr = nullptr;
            // if (this->arr != nullptr)
            // {
            //     delete[] this->arr;
            // }
            this->length = 0;
        }
        //DynamicArray() : arr(nullptr), length(0) {}
        DynamicArray(const char *_arr)
        {
            this->length = strlen(_arr);
            this->arr = new char[this->length + 1];
            strcpy(this->arr, _arr);
        }
        DynamicArray &operator = (const DynamicArray &other)
        {
            if (this != &other)
            {
                this->length = other.length;
                if (this->arr != nullptr)
                {
                    delete[] this->arr;
                }
                this->arr = new char[this->length + 1];
                strcpy(this->arr, other.arr);
            }
            
            return *this;
        }
        DynamicArray(const DynamicArray &other)
        {
            this->length = other.length;
            this->arr = new char[this->length + 1];
            strcpy(this->arr, other.arr);
        }
        ~DynamicArray()
        {
            delete[] this->arr;
        }
};

int main()
{
    DynamicArray a;
    a.setArr("test");
    DynamicArray b = a;
    b.setCharAt(5, '=');
    cout << a.getArr();

    return 0;
}