#include <iostream>
#include <string>
#include <fstream>
#include "ConsoleHandler.h"
#include "HotelClass.h"
using namespace std;

int main()
{
    Room room;

    ConsoleHandler console;

    string command;
    
    while(true)
    {
        getline(cin, command);
        console.processCommand(command);
    }

    /*if(command[0] == 'c')
    {
        if (command[5] == 'i')
        {
            //checkin()
        }
        else if (command[5] == 'o')
        {
            //checkout();
        }
    }
    else if (command[0] == 'a')
    {
        //availability();
    }
    else if (command[0] == 'r')
    {
        //remove();
    }
    else if (command[0] == 'f')
    {
        if (command[4] == '!')
        {
            //findExclamation();
        }
        else
        {
            //find();
        }
    }
    else if (command[0] == 'u')
    {
        //unavailable();
    }*/

    return 0;
}