#include "ArrayOfEvents.h"

Event& ArrayOfEvents::operator[] (int i)
{
    return events[i];
}

void ArrayOfEvents::add(DateTime d, int h, string n)
{
    for (int i = 0; i < 20; i++)
    {
        if (i + 1 == h)
        {
            events[i].changeSettings(d, h, n);
        }
    }

    cout << "Event added";
}

void ArrayOfEvents::returnQuery(DateTime d, int n)
{

}

void ArrayOfEvents::reserve(int r, int s, DateTime d, string _name, string _note)
{

}

void ArrayOfEvents::cancel(int r, int s, DateTime d, string n)
{

}

void ArrayOfEvents::purchase(int r, int s, DateTime d, string n)
{

}

void ArrayOfEvents::reservedButNotPaid(DateTime d, string n)
{

}

void ArrayOfEvents::isValid(string c)
{

}

void ArrayOfEvents::returnBoughtTickets(DateTime dateFrom, DateTime dateTo, int h)
{

}

/*ostream& operator << (ostream& output, const ArrayOfEvents& events)
{
    for (int i = 0; i < 20; i++)
    {
        cout << events.events[i];
    }
    return output;
}*/