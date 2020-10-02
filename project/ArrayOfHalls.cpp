#include "ArrayOfHalls.h"

void ArrayOfHalls::add(DateTime d, int h, string n)
{
    for (int i = 0; i < 10; i++)
    {
        if (i + 2 == h)
        {
            //halls.changeSettings(d, h, n);
            events[i].changeSettings(d, h, n);
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cout << events[i].getDate() << " " << events[i].getName() << endl;
    }

    cout << "Event added";
}

void ArrayOfHalls::returnQuery(DateTime d, string n)
{
    for (int i = 0; i < 10; i++)
    {
        if (events[i].getDate() == d && events[i].getName() == n)
        {
            //TODO
        }
    }
}

void ArrayOfHalls::reserve(int r, int s, DateTime d, string _name, string _note)
{
    /*for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 15 ; j++)
        {
            for (int k = 0; k < 15; k++)
            {
                cout << events[i].getName() << " " << _name << endl;
                cout << j + 1 << " " << r << endl;
                cout << k + 1 << " " << s << endl;
                if (events[i + 1].getName() == _name && j + 1 == r && k + 1 == s)
                {
                    cout << events[i + 1].getName() << " " << _name << endl;
                    cout << j + 1 << " " << r << endl;
                    cout << k + 1 << " " << s << endl;
                    tickets[i][j][k].changeSettings(j, k, d, _note, _name, "reserved");
                }
            }
        }
    }*/

    /*for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            for (int k = 0; k < 15; k++)
            {
                cout << tickets[i][j][k] << endl;  
            }
            cout << endl;
        }
        cout << endl;
    }*/
}

void ArrayOfHalls::cancel(int r, int s, DateTime d, string n)
{

}

void ArrayOfHalls::purchase(int r, int s, DateTime d, string n)
{

}

void ArrayOfHalls::reservedButNotPaid(DateTime d, string n)
{

}

void ArrayOfHalls::isValid(string c)
{

}

void ArrayOfHalls::returnBoughtTickets(DateTime dateFrom, DateTime dateTo, int h)
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
