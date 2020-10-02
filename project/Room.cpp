#include "Room.h"

Room::Room(const int _nomer, const DateTime _dF, const DateTime _dT, const string _note)
{
    this->nomer = _nomer;
    this->dateFrom = _dF;
    this->dateTo = _dT;
    this->note = _note; 
    if (this->nomer <= 100)
    {
        this->beds = 1;
    }
    else if (this->nomer > 100 && this->nomer <= 200)
    {
        this->beds = 2;
    }
    else if (this->nomer > 200 && this->nomer <= 300)
    {
        this->beds = 3;
    }
    else
    {
        this->beds = 4;
    }
}

Room::Room(const Room& other)
{
    this->nomer = other.nomer;
    this->dateFrom = other.dateFrom;
    this->dateTo = other.dateTo;
    this->note = other.note;
    this->beds = other.beds;
}
Room& Room::operator= (const Room& other)
{
    if (this != &other)
    {
        this->nomer = other.nomer;
        this->dateFrom = other.dateFrom;
        this->dateTo = other.dateTo;
        this->note = other.note;
        this->beds = other.beds;
    }
    return *this;
}

int Room::getNumber()
{
    return this->nomer;
}

DateTime Room::getDateFrom() 
{
    return this->dateFrom;
}

DateTime Room::getDateTo()
{
    return this->dateTo;
}

ostream& operator << (ostream& output, const Room& room)
{
    output << "Room number: " << room.nomer << '\n' << "This room is rented from " 
           << room.dateFrom << " to " << room.dateTo << '\n' << "Note:" << room.note << "\nNumber of beds: " << room.beds << endl;
    return output;
}