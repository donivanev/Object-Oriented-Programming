#include <iostream>
using namespace std;

template <typename T>
bool member(T array[], int n, T x)
{
    bool isIn = false;

    for (int i = 0; i < n; i++)
    {
        if (x == array[i])
        {
            isIn = true;
        }
    }
    
    if (isIn)
    {
        return true;
    }

    return isIn;
}

int main()
{
    int n;
    cin >> n;

    //int arr[10] = {3, 4, 5, 7, 9};
    //int arr[10] = {1, 2, 3, 4, 6};
    char arr[10] = {'f', 'a', 'l', 's', 'e'};

    cout << member(arr, 5, 'f');

    return 0;
}