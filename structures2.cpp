#include <iostream>
#include <cstring>
using namespace std;

struct Product
{
    char description[32]; // or char *description
    int partNum;
    double cost;  
};

int main()
{

    Product product1, product2;

    strcpy(product1.description, "screw driver");
    product1.partNum = 456;
    product1.cost = 5.50; 

    strcpy(product2.description, "hammer");
    product2.partNum = 324;
    product2.cost = 8.20; 

    cout << product1.description << " "
         << product1.partNum << " "
         << product1.cost << endl; 

    cout << product2.description << " "
         <<product2.partNum << " "
         <<product2.cost << endl; 

    Product arrOfProducts[5];

    strcpy(arrOfProducts[0].description, "screw driver");
    arrOfProducts[0].partNum = 456;
    arrOfProducts[0].cost = 5.50; 

    strcpy(arrOfProducts[1].description, "hammer");
    arrOfProducts[1].partNum = 324;
    arrOfProducts[1].cost = 8.20; 

    strcpy(arrOfProducts[2].description, "socket");
    arrOfProducts[2].partNum = 777;
    arrOfProducts[2].cost = 6.80; 

    strcpy(arrOfProducts[3].description, "plier");
    arrOfProducts[3].partNum = 123;
    arrOfProducts[3].cost = 10.80; 

    strcpy(arrOfProducts[4].description, "hand-saw");
    arrOfProducts[4].partNum = 555;
    arrOfProducts[4].cost = 12.80; 

    for (int i = 0; i < 5; i++)
    {
        cout << arrOfProducts[i].description << " "
             << arrOfProducts[i].partNum << " "
             << arrOfProducts[i].cost << endl; 
    }

    return 0;
}