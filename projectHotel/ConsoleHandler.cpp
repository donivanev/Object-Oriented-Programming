#include "ConsoleHandler.h"

void ConsoleHandler::splitString(string cmd, vector<string>& v)
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

void ConsoleHandler::toDate(string& str, int& y, int& m, int& d)
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

bool ConsoleHandler::isValidDateTime(int year, int month, int day)
{
    bool isValid = false;

    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;

    return true;
}

bool ConsoleHandler::isNumber(string str)
{
    return (atoi(str.c_str()));
}

void ConsoleHandler::checkFunction(string firstWord, string command)
{
    vector<string> vector;

    if (firstWord == "checkin")
    {
        int y1, m1, d1, y2, m2, d2, index;
        string note;
        splitString(command, vector);
        toDate(vector.at(2), y1, m1, d1);
        toDate(vector.at(3), y2, m2, d2);
        DateTime dateFrom(y1, m1, d1);
        DateTime dateTo(y2, m2, d2);

        for (int i = 4; i < vector.size(); i++)
        {
            if (i == vector.size() - 1 && isNumber(vector.at(i)))
            {
                continue;
            }
            else
            {
                note = note + " " + vector.at(i);
            }
        }

        if (stoi(vector.at(1)) < 1)
        {
            cout << "The hotel hasn't got negative rooms." << endl;
        }
        else if (stoi(vector.at(1)) > 20)
        {
            cout << "The hotel has only 20 rooms." << endl;
        }
        else
        {
            if (isValidDateTime(y1, m1, d1) == false || isValidDateTime(y2, m2, d2) == false)
            {
                cout << "Please enter valid DateTime!" << endl;
            }
            else
            {
                string last = vector.at(vector.size() - 1);
                if (isNumber(last))
                {
                    hotel.checkin(stoi(vector.at(1)), dateFrom, dateTo, note, stoi(vector.at(vector.size() - 1)));
                }
                else
                {
                    hotel.checkin(stoi(vector.at(1)), dateFrom, dateTo, note, 0);
                }
            }
        }
    }
    else if (firstWord == "checkout")
    {
        splitString(command, vector);
        if (vector.size() == 1)
        {
            cout << "Please specify which room you would like to checkout" << endl;
        }
        else
        {
            if (stoi(vector.at(1)) < 1 || stoi(vector.at(1)) > 20)
            {
                cout << "No such room number!" << endl;
            }
            else
            {
                hotel.checkout(stoi(vector.at(1)));
            }
        }
    }
    else if (firstWord == "availability")
    {
        DateTime dGlobal;
        int y1, m1, d1;
        string ifToday = "";
        splitString(command, vector);

        if (vector.size() == 1)
        {
            DateTime d(2020, 05, 31);
            dGlobal = d;
            ifToday = "today";

            hotel.availability(dGlobal, ifToday);
        }
        else
        {
            toDate(vector.at(1), y1, m1, d1);
            DateTime d(y1, m1, d1);
            dGlobal = d;

            if (isValidDateTime(y1, m1, d1) == false)
            {
                cout << "Please enter a valid DateTime!" << endl;
            }
            else
            {
                hotel.availability(dGlobal, ifToday);
            }
        }
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
        hotel.findExclamation(stoi(vector.at(1)), dateFrom, dateTo);
    }
    else if (firstWord == "find")
    {
        splitString(command, vector);
        int y1, m1, d1, y2, m2, d2;
        toDate(vector.at(2), y1, m1, d1);
        toDate(vector.at(3), y2, m2, d2);
        DateTime dateFrom(y1, m1, d1);
        DateTime dateTo(y2, m2, d2);
        hotel.find(stoi(vector.at(1)), dateFrom, dateTo);
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

void ConsoleHandler::open(string path)
{
    string PATH = path;
    
    if (f_inout.is_open())
    {
        cout << "Already opened file" << endl;
    }
    else
    {
        f_inout.open(PATH);

        if (!f_inout.is_open())
        {
            cout << "not a valid path"<<endl;
            return;
        }

        cout << "Opened successfully" << endl;

        char* token;
        token = strtok(&PATH[0], "\\");

        while (token != NULL)
        {
            f_fileName = token;
            token = strtok(NULL, "\\");
        }   

        if (token != nullptr) delete[] token;
    } 
}

void ConsoleHandler::close()
{
    if(!f_inout.is_open())
    {
        cout << "Invalid command" << endl;
        cout << "Try opening a file first. The command is open." << endl;
    }
    else
    {
        cout << "Successfully closed " << f_fileName << endl;
        f_fileName = "";
        f_filePath = "";
        f_inout.close();
    }
}

void ConsoleHandler::save()
{
    if(!f_inout.is_open())
    {
        cout << "Invalid command" << endl;
        cout << "Try opening a file first. The command is open." << endl;
    }
    else
    {
        f_inout.clear();

        f_inout << hotel;
        cout << "Successfully saved in "<< f_fileName << endl;
    }
}

void ConsoleHandler::saveAs(string path)
{
    string PATH = path;

    if(f_filePath == path)
    {   
        f_inout << hotel;
    }
    else
    {
        fstream newstream(path);

        if(!newstream.is_open())
        {
            cout << "Invalid command" << endl;
            cout << "Try opening a file first. The command is open." << endl;
        }
        else
        {
            newstream.clear();

            newstream << hotel;

            char* token;
            token = strtok(&PATH[0], "\\");
            string currentName;
            
            while (token != NULL)
            {
                currentName = token;
                token = strtok(NULL, "\\");
            } 

            cout << "Successfully saved in "<< currentName << endl;
            newstream.close();
            if(token != nullptr) delete[] token;
        }
    }
    /*if (path == f_filePath)
    {
        f_inout << f_fileName << endl;
        for (int i = 0; i < 10; i++)
        {
            f_inout << hotel[i];
        }

        cout << "Successfully saved." << endl;
    }
    else
    {
        fstream newstream(path);
        if (!newstream.is_open())
        {
            newstream.close();
            ofstream openFile(path);
            if (!openFile.is_open())
            {
                cout << "file could not open" << endl;
                return;
            }
            else
            {
                openFile.close();
                newstream.open(path);
                if (!newstream.is_open())
                {
                    cout << "Not a valid path fo saving data." << endl;
                    return;
                }
                else

                {
                    newstream << f_fileName << endl;

                    for (int i = 0; i < 10; i++)
                    {
                        newstream << hotel[i] << endl;
                    }

                    cout << "Successfully saved in file" << endl;
                    newstream.close();
                }
            }
        }
        else
        {
            newstream.close();
            newstream.open(path, ios::out | ios::trunc);
            newstream.close();
            newstream.open(path);


            for (int i = 0; i < 10; i++)
            {
                newstream << hotel[i] << endl;
            }

            cout << "Successfully saved in file" << endl;
            newstream.close();
        }
    }*/
}

void ConsoleHandler::exit()
{
    if(f_inout.is_open())
    {
        f_inout.close();
    }
    cout << "Exiting the program..." << endl;
    terminate();
}

void ConsoleHandler::help()
{
    cout << "The following commands are supported :\n"
         << "open <file>    opens <file>\n"
         << "close          closes currently opened file\n"
         << "save           saves the currently open file\n"
         << "saveas <file>  saves the currently open file in <file>\n"
         << "help           prints this information\n"
         << "exit           exists the program" << endl;
}

void ConsoleHandler::processCommand(string firstWord, string command)
{   
    //char* token;
    //token = strtok(&command[0], " ");
    //commandName = token;

    string  _command = command, path = "";
    vector<string> v;

    if (firstWord == "open")
    {  
        splitString(command, v);
        path = v[1];
        f_filePath = path;
        open(path);  
    }
    else if (firstWord == "save")
    {
        save();
    }
    else if (firstWord == "saveas")
    {
        int place = 0;
        string token, delimeter = " ";

        place = _command.find(delimeter);
        token = _command.substr(0, place);
        v.push_back(token);
        _command.erase(0, place + delimeter.length());
        v.push_back(_command);

        path = v[1];
        if(path == "")
        {
            cout << "Invalid command.Try again!";
        }
        else
        {
            saveAs(path);
        }
    }
    else if (firstWord == "close")
    {
        close();
    }
    else if (firstWord == "help")
    {
        help();
    }
    else if (firstWord == "exit")
    {
        exit();
    }
    else
    {
        if (f_inout.is_open())
        {
            checkFunction(firstWord, _command);
        }
        else
        {
            cout << "Invalid command" << endl;
            cout << "Try opening a file first. The command is open." << endl;
        }
    }
}