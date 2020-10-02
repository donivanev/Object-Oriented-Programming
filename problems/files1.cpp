#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
using namespace std;

struct Product
{
    char description[32]; // or char *description
    int partNum;
    double cost;  
};

bool isNum(char *str) 
{
    int i = 0;

    while(str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
    {
        ++i;
    }

    return str[i] == '\0';
}

int main()
{

    Product products[5];

    ifstream in_file ("myfilein.txt");
    for (int i = 0; i < 5; i++)
    {
        in_file.getline(products[i].description, 100);
        in_file >> products[i].partNum;
        in_file >> products[i].cost;
        in_file.ignore();

        // char tmp[100];
        // char descr_tmp[100] = "";
        // bool isFirst = true;

        // in_file >> tmp;

        // while(!isNum(tmp)) 
        // {
        //     if (!isFirst) 
        //     {
        //         strcat(descr_tmp, " ");
        //     }
        //     else 
        //     {
        //         isFirst = false;
        //     }
            
        //     strncat(descr_tmp, tmp, 100);
        //     in_file >> tmp;
        // }

        // strncpy(products[i].description, descr_tmp, 100);

        // products[i].partNum = atoi(tmp);

        // in_file >> products[i].cost;
    }

    ofstream out_file ("myfileout.txt");
    for (int i = 0; i < 5; i++)
    {
        out_file << products[i].description << " "
                 << products[i].partNum << " "
                 << products[i].cost << endl;
    }

    return 0;
}