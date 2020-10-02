#pragma once

#include "ArrayOfRooms.h"

class Hotel
{
    ArrayOfRooms arrayOfRooms;

public:

    void checkin(int room, DateTime from, DateTime to, string note);

    void checkout(int number);

    void availability(DateTime date, string today);

    void report(DateTime from, DateTime to);

    void find(int beds, DateTime from, DateTime to);

    void findExclamation(int beds, DateTime from, DateTime to);

    void unavailable(int number, DateTime from, DateTime to, string note);

    friend ostream& operator << (ostream& output, const Hotel& room);

    void printRooms();

};