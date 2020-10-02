#include "Event.h"

int counter = 0;

Event::Event(const DateTime _d, const string _name, const int num)
{
    counter++;
    this->date = _d;
    this->name = _name;
    this->numberOfHall = num;
}

Event::Event(const Event& other)
{
    date = other.date;
    name = other.name;
    numberOfHall = other.numberOfHall;
}

void Event::changeSettings(DateTime _d, int _hall, string _name)
{
    this->date = _d;
    this->name = _name;
    this->numberOfHall = _hall;
}

Event& Event::operator=(const Event& other)
{
    if (this != &other)
    {
        date = other.date;
        name = other.name;
        numberOfHall = other.numberOfHall;
    }

    return *this;
}

DateTime Event::getDate()
{
    return this->date;
}

string Event::getName()
{
    return this->name;
}

/*void Event::print()
{
    for (int i = 0; i < 20; i++)
    {
        cout << tickets[i];
    }
}*/

/*ostream& operator << (ostream& output, const Event& events)
{
    for (int i = 0; i < sizeOfTickets; i++)
    {
        cout << events.tickets[i];
    }
    return output;
}*/