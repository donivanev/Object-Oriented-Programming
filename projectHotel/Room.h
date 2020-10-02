#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include "DateTime.h"
using namespace std;

class Room
{
private:
    int nomer, guests;
    DateTime dateFrom, dateTo;
    string note;

public:
    Room(const int _nomer = 1, const DateTime _dF = DateTime(), const DateTime _dT = DateTime(), 
        const string _note = "", const int guests = 0);
    void changeSettings(DateTime d1, DateTime d2, string note, int guests);

    int getNumber();
    DateTime getDateFrom();
    DateTime getDateTo();
    int getGuests();
    string getNote();

    friend ostream& operator << (ostream& output, const Room& room);
};
