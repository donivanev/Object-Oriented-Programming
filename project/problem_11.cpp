#include "ConsoleHandler.h"

void splitString(string cmd, vector<string>& v)
{
    int place = 0;
    string token, delimeter = " ";

    while ((place = cmd.find(delimeter)) != string::npos)
    {
        token = cmd.substr(0, place);
        v.push_back(token);
        cmd.erase(0, place + delimeter.length());
    }
    v.push_back(cmd);

    //for (string s : v)
    //{
        //cout << s << endl;
    //}
}

void toDate(string& str, int& y, int& m, int& d)
{
    int place = 0;
    string token, delimeter = "-";
    vector<string> v;

    while ((place = str.find(delimeter)) != string::npos)
    {
        token = str.substr(0, place);
        v.push_back(token);
        str.erase(0, place + delimeter.length());
    }
    v.push_back(str);

    y = stoi(v.at(0));
    m = stoi(v.at(1));
    d = stoi(v.at(2));
}

void checkFunction(string firstWord, string command, Hotel& hotel)
{
    vector<string> vector;

    if (firstWord == "checkin")
    {
        int y1, m1, d1, y2, m2, d2;
        string note;
        splitString(command, vector);
        toDate(vector.at(2), y1, m1, d1);
        toDate(vector.at(3), y2, m2, d2);
        DateTime dateFrom(y1, m1, d1);
        DateTime dateTo(y2, m2, d2);
        for (int i = 4; i < vector.size(); i++)
        {
            note = note + " " + vector.at(i);
        }
        if (stoi(vector.at(1)) < 1)
        {
            cout << "The hotel hasn't got negative rooms." << endl;
        }
        else if (stoi(vector.at(1)) > 300)
        {
            cout << "The hotel has only 300 rooms." << endl;
        }
        else
        {
            hotel.checkin(stoi(vector.at(1)), dateFrom, dateTo, note);
            hotel.printRooms();
        }
    }
    else if (firstWord == "checkout")
    {
        splitString(command, vector);
        if (vector.size() == 1)
        {
            cout << "Please specify which room you would like to checkout";
        }
        else
        {
            hotel.checkout(stoi(vector.at(1)));
        }
    }
    else if (firstWord == "availability")
    {
        DateTime dGlobal;
        string ifToday = "";
        splitString(command, vector);

        if (vector.size() == 1)
        {
            DateTime d(2020, 05, 31);
            dGlobal = d;
            ifToday = "today";
        }
        else
        {
            int y1, m1, d1;
            toDate(vector.at(1), y1, m1, d1);
            DateTime d(y1, m1, d1);
            dGlobal = d;
        }

        hotel.availability(dGlobal, ifToday);
    }
    else if (firstWord == "report")
    {
        splitString(command, vector);
        int y1, m1, d1, y2, m2, d2;
        toDate(vector.at(1), y1, m1, d1);
        toDate(vector.at(2), y2, m2, d2);
        DateTime dateFrom(y1, m1, d1);
        DateTime dateTo(y2, m2, d2);
        hotel.report(dateFrom, dateTo);
    }
    else if (firstWord == "find!")
    {
        splitString(command, vector);
        int y1, m1, d1, y2, m2, d2;
        toDate(vector.at(2), y1, m1, d1);
        toDate(vector.at(3), y2, m2, d2);
        DateTime dateFrom(y1, m1, d1);
        DateTime dateTo(y2, m2, d2);
        //hotel.findExclamation(stoi(vector.at(1)), dateFrom, dateTo);
    }
    else if (firstWord == "find")
    {
        splitString(command, vector);
        int y1, m1, d1, y2, m2, d2;
        toDate(vector.at(2), y1, m1, d1);
        toDate(vector.at(3), y2, m2, d2);
        DateTime dateFrom(y1, m1, d1);
        DateTime dateTo(y2, m2, d2);
        //hotel.find(stoi(vector.at(1)), dateFrom, dateTo);
    }
    else if (firstWord == "unavailable")
    {
        int y1, m1, d1, y2, m2, d2;
        string note;
        splitString(command, vector);
        toDate(vector.at(2), y1, m1, d1);
        toDate(vector.at(3), y2, m2, d2);
        DateTime dateFrom(y1, m1, d1);
        DateTime dateTo(y2, m2, d2);
        for (int i = 4; i < vector.size(); i++)
        {
            note = note + " " + vector.at(i);
        }

        hotel.unavailable(stoi(vector.at(1)), dateFrom, dateTo, note);
    }
    else
    {
        cout << "Invalid command!" << endl;
    }
}

int main()
{
    Hotel hotel;
    Room room;
    ArrayOfRooms arrOfRooms;
    ConsoleHandler console;
    string command;

    while (true)
    {
        getline(cin, command);
        string firstWord = command.substr(0, command.find(" "));
        checkFunction(firstWord, command, hotel);
        arrOfRooms.print();
        //console.processCommand(command);
    }

    return 0;
}