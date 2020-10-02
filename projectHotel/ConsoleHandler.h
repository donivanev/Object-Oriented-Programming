#pragma once
#pragma warning(disable:4996)
#include <fstream>
#include <algorithm>
#include <string>
#include "HotelClass.h"

class ConsoleHandler
{

    private:
    fstream f_inout;
    string f_filePath, f_fileName;
    Hotel hotel;

    void splitString(string cmd, vector<string>& v);
    void toDate(string& str, int& y, int& m, int& d);
    bool isValidDateTime(int year, int month, int day);
    bool isNumber(string str);
    void checkFunction(string firstWord, string command);

    void open(string path);
    void close();
    void save();
    void saveAs(string path);
    void exit();
    void help();

    public:

    void processCommand(string firstWord, string command);
};
