#pragma once

#include <vector>
#include "Room.h"

class ArrayOfRooms
{
    vector<Room> rooms;

    public:

    bool contains(int r, DateTime f, DateTime t);
    void add(int r, DateTime f, DateTime t, string n);
    void check(DateTime date, string today);
    void release(int number);
    void list(DateTime dateFrom, DateTime dateTo);
    void findRoom(int number, DateTime dateFrom, DateTime dateTo);
    void findVIPRoom(int number, DateTime dateFrom, DateTime dateTo);
    void freeze(int number, DateTime dateFrom, DateTime dateTo, string note);
    int getSize();

    void print();
    friend ostream& operator << (ostream& output, const ArrayOfRooms& rooms);
};
