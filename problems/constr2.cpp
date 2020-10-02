#include <iostream>
using namespace std;

class ArrayOfNumbers
{
    int *arrOfNums;
    int size;
    int capacity;

    public:
    ArrayOfNumbers()
    {
        capacity = 2;
        size = 0;
        arrOfNums = new int[capacity];
    }
    
    void push (const int x)
    {
        if(size == capacity)
        {
            capacity *= 2;
            int *bigger_buffer = new int [capacity];
            
            for (size_t i = 0; i < size; i++)
            {
                bigger_buffer[i] = arrOfNums[i];
            }

            delete[] arrOfNums;
            arrOfNums = bigger_buffer;
        }
        
        arrOfNums[size] = x;
        ++size;
    }

    int getElement(int index)
    {
        return arrOfNums[index];
    }

    int getSize()
    {
        return size;
    }

    ~ArrayOfNumbers()
    {
        delete[] arrOfNums;
    }
};

class NumbersSumator
{
    int resultSum, counter, avrg;
    ArrayOfNumbers *arrOfNums;

    public:

    NumbersSumator(const int _sum = 0):resultSum(_sum)
    {
        this->arrOfNums = new ArrayOfNumbers;
        avrg = 0;
    }

    int sum()
    {
        return this->resultSum;
    }

    int add(int x)
    {
        this->counter++;
        arrOfNums->push(x);
        return this->resultSum += x;
    }

    int sub(int x)
    {
        this->counter++;
        arrOfNums->push(-x);
        return this->resultSum -= x;
    }

    int num()
    {
        return this->counter;
    }

    int average()
    {
        cout<<arrOfNums->getSize()<<endl;
        for(int i = 0; i < arrOfNums->getSize(); i++)
        {
            avrg += arrOfNums->getElement(i);
            cout <<avrg << endl;
        }

        return avrg / arrOfNums->getSize();
    }

    ~NumbersSumator ()
    {
        delete resultSum;
    }
};

int main()
{
    NumbersSumator nums(10);
    nums.add(40);
    nums.add(20);
    nums.sub(50);

    cout << nums.sum() << endl;
    cout << nums.average();

    return 0;
}