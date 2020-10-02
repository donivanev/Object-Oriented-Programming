#include "HotelClass.h"

void Hotel::checkin(int room, DateTime from, DateTime to, string note)
{
    arrayOfRooms.add(room, from, to, note);
}

void Hotel::checkout(int number)
{
    arrayOfRooms.release(number);
}

void Hotel::availability(DateTime date, string today)
{
    arrayOfRooms.check(date, today);
}

void Hotel::report(DateTime from, DateTime to)
{
    arrayOfRooms.list(from, to);
}

void Hotel::find(int beds, DateTime from, DateTime to)
{
    arrayOfRooms.findRoom(beds, from, to);
}

void Hotel::findExclamation(int beds, DateTime from, DateTime to)
{
    arrayOfRooms.findVIPRoom(beds, from, to);
}

void Hotel::unavailable(int number, DateTime from, DateTime to, string note)
{
    arrayOfRooms.freeze(number, from, to, note);
}

ostream& operator << (ostream& output, const Hotel& hotel)
{
    output << hotel;
    return output;
}

void Hotel::printRooms()
{
    arrayOfRooms.print();
}