#include <iostream>
using namespace std;

struct Point
{
    double x;
    double y;
};  

void inputPoints(int size, Point points[])
{
    for (int i = 0; i < size; i++)
    {
        cout << "x" << i << " = ";
        cin >> points[i].x;
        cout << "y" << i << " = ";
        cin >> points[i].y;
    }
}

void sortPoints(int size, Point points[])
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (points[j].x > points[j + 1].x)
            {
                int helper = points[j].x;
                points[j].x = points[j + 1].x;
                points[j + 1].x = helper;
            }
        }
    }
}

void outputPoints(int size, Point points[])
{
    for (int i = 0; i < size; i++)
    {
        cout << "x" << i << " = " << points[i].x << endl;
        cout << "y" << i << " = " << points[i].y << endl;
    }
}

int main()
{
    int n;
    cout << "How many points: ";
    cin >> n;

    Point points[100];

    inputPoints(n, points);
    sortPoints(n, points);
    outputPoints(n, points);

    return 0;
}