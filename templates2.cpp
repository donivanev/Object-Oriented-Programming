#include <iostream>
using namespace std;

template <typename T>
bool ordered(T array[], int n)
{
    int counter = 0;

    for (int i = 0; i < n; i++)
    {
        if (array[i] < array[i + 1])
        {
            counter++;
        }
    }
    
    if (counter == n - 1)
    {
        return true;
    }

    return false;
}

int main()
{
    int n;
    cin >> n;

    //int arr[10] = {3, 4, 6, 2, 1};
    int arr[10] = {1, 2, 3, 4, 6};

    cout << ordered(arr, 5);

    return 0;
}