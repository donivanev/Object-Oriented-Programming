#include "ArrayOfRooms.h"

int ArrayOfRooms::getSize()
{
    return rooms.size();
}

bool ArrayOfRooms::contains(int r, DateTime f, DateTime t)
{
    for (int i = 0; i < rooms.size(); i++)
    {
        if (rooms.at(i).getNumber() == r &&
            ((rooms.at(i).getDateFrom() <= f && rooms.at(i).getDateTo() >= f) && 
                (rooms.at(i).getDateFrom() <= t && rooms.at(i).getDateTo() >= t)))
        {
            return true;
        }
    }
    return false;
}

void ArrayOfRooms::add(int r, DateTime f, DateTime t, string n)
{
    Room newRoom(r, f, t, n);
    if (!contains(r, f, t))
    {
        rooms.push_back(newRoom);
    }
    else
    {
        cout << "This room is already rented." << endl;
    }
}

void ArrayOfRooms::check(DateTime date, string today)
{
    for (int i = 0; i < rooms.size(); i++)
    {
        if (date > rooms.at(i).getDateFrom() && date < rooms.at(i).getDateTo())
        {
            if (today == "today")
            {
                cout << "Room number " << rooms.at(i).getNumber() << " is not free today" << endl;
            }
            else
            {
                cout << "Room number " << rooms.at(i).getNumber() << " is not free on this date" << endl;
            }
        }
        else
        {
            if (today == "today")
            {
                cout << "Room number " << rooms.at(i).getNumber() << " is free today" << endl;
            }
            else
            {
                cout << "Room number " << rooms.at(i).getNumber() << " is free on this date" << endl;
            }
        }
    }
}

void ArrayOfRooms::release(int number)
{
    bool isInArray = false;

    for (int i = 0; i < rooms.size(); i++)
    {
        if (rooms.at(i).getNumber() == number)
        {
            isInArray = true;
            rooms.at(i) = Room(rooms.at(i).getNumber(), DateTime(), DateTime(), "");
            cout << "Room succesfully checked out!" << endl;
        }
    }

    if (!isInArray)
    {
        cout << "The room you want to checkout is free. First you have to checkin!" << endl;
    }
}

void ArrayOfRooms::list(DateTime dateFrom, DateTime dateTo)
{
    vector<int> v;

    for (int i = 0; i < rooms.size(); i++)
    {
        v.push_back(rooms.at(i).getDateTo().getDay() - rooms.at(i).getDateFrom().getDay());
    }

    for (int i : v)
    {
        cout << i << endl;
    }
}

void ArrayOfRooms::findRoom(int number, DateTime dateFrom, DateTime dateTo)
{
    vector<int> v;


}

void ArrayOfRooms::findVIPRoom(int number, DateTime dateFrom, DateTime dateTo)
{
    vector<int> v;


}

void ArrayOfRooms::freeze(int number, DateTime dateFrom, DateTime dateTo, string note)
{
    vector<int> v;

    
}

void ArrayOfRooms::print()
{
    for (int i = 0; i < rooms.size(); i++)
    {
        cout << rooms[i];
    }
}

ostream& operator << (ostream& output, const ArrayOfRooms& rooms)
{
    for (int i = 0; i < rooms.rooms.size(); i++)
    {
        cout << rooms.rooms[i];
    }
    return output;
}