#include "HotelClass.h"

Room& Hotel::operator[](int i)
{
    return arrayOfRooms[i];
}

void Hotel::checkin(int room, DateTime from, DateTime to, string note, int guests)
{
    arrayOfRooms.add(room, from, to, note, guests);
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

void Hotel::printRooms()
{
    arrayOfRooms.print();
}

ostream& operator << (ostream& output, const Hotel& hotel)
{
    output << hotel.arrayOfRooms;
    return output;
}