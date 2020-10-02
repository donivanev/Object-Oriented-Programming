#pragma once
#include <vector>
#include "Room.h"
#include "Unavailable.h"

const int sizeOfRooms = 20;
const int sizeOfStatus = 20;
const int sizeOfDays = 20;
const int sizeOfUnavailable = 20;

class ArrayOfRooms
{
    Room rooms[sizeOfRooms];
    string status[sizeOfStatus] = { "checkedout" };
    int daysInRoom[sizeOfDays] = { 0 };
    Unavailable unavailable[sizeOfUnavailable];

    public:

    Room& operator [] (int i);
    void add(int r, DateTime f, DateTime t, string n, int beds);
    void check(DateTime date, string today);
    void release(int number);
    void list(DateTime dateFrom, DateTime dateTo);
    void findRoom(int number, DateTime dateFrom, DateTime dateTo);
    void findVIPRoom(int number, DateTime dateFrom, DateTime dateTo);
    void freeze(int number, DateTime dateFrom, DateTime dateTo, string note);

    void print();
    friend ostream& operator << (ostream& output, const ArrayOfRooms& rooms);
};
