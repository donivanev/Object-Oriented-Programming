#pragma once
#include "Event.h"

const int capacity = 20;
const int allSeats = 20;
const int allRows = 20;

class ArrayOfEvents
{
    string name;
    int allSeats[allRows][allSeats] = { 0 };
    Event events[capacity];

public:

    Event& operator [] (int i);

    void add(DateTime d, int h, string n);

    void returnQuery(DateTime d, int n);

    void reserve(int r, int s, DateTime d, string _name, string _note);

    void cancel(int r, int s, DateTime d, string n);

    void purchase(int r, int s, DateTime d, string n);

    void reservedButNotPaid(DateTime d, string n);

    void isValid(string c);

    void returnBoughtTickets(DateTime dateFrom, DateTime dateTo, int h);

    //friend ostream& operator << (ostream& output, const ArrayOfEvents& events);
};



