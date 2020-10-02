#include <iostream>
using namespace std;

template <typename T>
void input(T array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[10];
    //char arr[100];
    input(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];   
    }

    return 0;
}