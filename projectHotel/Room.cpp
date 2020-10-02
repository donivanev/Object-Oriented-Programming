#include "Room.h"

int counter = 1;

Room::Room(const int _nomer, const DateTime _dF, const DateTime _dT, const string _note, const int _guests)
{
    this->nomer = counter;
    counter++;
    this->dateFrom = _dF;
    this->dateTo = _dT;
    this->note = _note; 
    this->guests = _guests;
}

void Room::changeSettings(DateTime d1, DateTime d2, string _note, int _guests)
{
    dateFrom = d1;
    dateTo = d2;
    note = _note;
    guests = _guests;
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

int Room::getGuests()
{
    return this->guests;
}

string Room::getNote()
{
	return this->note;
}

ostream& operator << (ostream& output, const Room& room)
{
    output << "Room number: " << room.nomer << '\n' << "This room is rented from " 
           << room.dateFrom << " to " << room.dateTo << '\n' << "Note:" << room.note << "\nNumber of beds: " << room.guests << endl;
    return output;
}