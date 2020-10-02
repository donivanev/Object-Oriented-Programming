#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include "DateTime.h"
using namespace std;

class Room
{
private:
    int nomer, beds;
    DateTime dateFrom, dateTo;
    string note;

public:
    Room(const int _nomer = 1, const DateTime _dF = DateTime(), const DateTime _dT = DateTime(), const string _note = "");
    Room(const Room& other);
    Room& operator= (const Room& other);

    int getNumber();
    DateTime getDateFrom();
    DateTime getDateTo();

    friend ostream& operator << (ostream& output, const Room& room);
};
