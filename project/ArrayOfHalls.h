#pragma once
#include "Hall.h"

class ArrayOfHalls
{

private:
	//Hall halls[10];
    Ticket tickets[10][15][15];
    Event events[10];

public:

    void add(DateTime d, int h, string n);

    void returnQuery(DateTime d, string n);

    void reserve(int r, int s, DateTime d, string _name, string _note);

    void cancel(int r, int s, DateTime d, string n);

    void purchase(int r, int s, DateTime d, string n);

    void reservedButNotPaid(DateTime d, string n);

    void isValid(string c);

    void returnBoughtTickets(DateTime dateFrom, DateTime dateTo, int h);

};

