#include <iostream>
#include <cmath>
using namespace std;

struct polar
{
    double r;
    double t;
};

struct rect
{
    double x;
    double y;
};

void transferFromRToP(int size, rect array[])
{
    for (int i = 0; i < size; i++)
    {
        array[i].x = sqrt(pow(array[i].x, 2) + pow(array[i].y, 2)) * cos(atan(array[i].y / array[i].x));
        array[i].y = sqrt(pow(array[i].x, 2) + pow(array[i].y, 2)) * sin(atan(array[i].y / array[i].x));
    }
}

void transferFromPToR(int size, polar array[], rect array2[])
{
    for (int i = 0; i < size; i++)
    {
        array[i].r = sqrt(pow(array2[i].x, 2) + pow(array2[i].y, 2));
        array[i].t = atan(array2[i].y / array2[i].x);
    }
}

void printRectVector(int size, rect array[])
{
    for (int i = 0; i < size; i++)
    {
        cout << "x" << i << " = " << array[i].x << endl;
        cout << "y" << i << " = " << array[i].y << endl;
    }
}

void printPolarVector(int size, polar array[])
{
    for (int i = 0; i < size; i++)
    {
        cout << "x" << i << " = " << array[i].r << endl;
        cout << "y" << i << " = " << array[i].t << endl;
    }
}

int main()
{
    polar polarVectors[100];
    rect rectVectors[100]; 
    char c;

    cout << "Choose r or p: ";
    cin >> c;

    if (c == 'r')
    {
        int n;
        cout << "How many vectors: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cout << "x: ";
            cin >> rectVectors[i].x;
            cout << "y: ";
            cin >> rectVectors[i].y;
        }
        
        transferFromRToP(n, rectVectors);
        printRectVector(n, rectVectors);
    }
    else
    {
        int n;
        cout << "How many vectors: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cout << "r: ";
            cin >> polarVectors[i].r;
            cout << "t: ";
            cin >> polarVectors[i].t;
        }
        
        transferFromPToR(n, polarVectors, rectVectors);
        printPolarVector(n, polarVectors);
    }

    return 0;
}