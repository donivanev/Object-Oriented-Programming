#pragma once

#include "ArrayOfRooms.h"

class Hotel
{
    ArrayOfRooms arrayOfRooms;

public:

    Room& operator[](int i);
    void checkin(int room, DateTime from, DateTime to, string note, int guests);
    void checkout(int number);
    void availability(DateTime date, string today);
    void report(DateTime from, DateTime to);
    void find(int beds, DateTime from, DateTime to);
    void findExclamation(int beds, DateTime from, DateTime to);
    void unavailable(int number, DateTime from, DateTime to, string note);
    void printRooms();

    friend ostream& operator << (ostream& output, const Hotel& room);
};