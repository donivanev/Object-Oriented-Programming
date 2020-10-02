#pragma once
#include "DateTime.h"

class Unavailable
{
    int number;
    DateTime from, to;
    string note, status;

    public:
    void change(int num, DateTime d1, DateTime d2, string _note)
    {
        number = num;
        from = d1;
        to = d2;
        note = _note;
        status = "unavailable";
    }

    string getStatus()
    {
        return this->status;
    }

    int getNum()
    {
        return this->number;
    }

    DateTime getFrom()
    {
        return this->from;
    }

    DateTime getTo()
    {
        return this->to;
    }

    string getNote()
    {
        return this->note;
    }

    friend ostream& operator << (ostream& output, const Unavailable& unavailable)
    {
        cout << unavailable.number << " " << unavailable.from << " "
             << unavailable.to << " " << unavailable.note;
        return output;
    }
};