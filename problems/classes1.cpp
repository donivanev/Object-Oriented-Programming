#include <iostream>
using namespace std;

class Time
{
    int hours;
    int minutes;

    public:
    Time ()
    {
        hours = 0;
        minutes = 0;
    }

    void init (const int h, const int m)
    {
        hours = h;
        minutes = m;
    }

    bool operator < (Time other)
    {
        if (other.hours > hours)
        {
            if (other.minutes > minutes)
            {
                return true;
            }
        }
        
        return false;
    }

    Time operator + (Time other)
    {
        Time result;
        // 5:30 + 10:20 = 15:50
        // 10:20 + 15:50 = 25:70 = 02:20
        result.hours = hours + other.hours;
        result.minutes = minutes + other.minutes;
        if (result.hours >= 24)
        {
            result.hours -= 24;
            if (result.minutes >= 60)
            {
                result.hours += result.minutes / 60;
                result.minutes = result.minutes - 60;
            }
        }
        
        return result;
    }

    Time operator - (Time other)
    {
        Time result;
        // 10:20 - 5:30 = 4:50
        result.hours = hours - other.hours;
        result.minutes = minutes - other.minutes;
        if (result.hours >= 24)
        {
            result.hours -= 24;
            if (result.minutes >= 60)
            {
                result.hours += result.minutes / 60;
                result.minutes = result.minutes - 60;
            }
        }
        return result;
        
    }

    Time operator * (int x)
    {
        Time result;
        // 10:20 * 5 = 50:100 = 0:3100
        result.hours = hours * x;
        result.minutes = minutes * x;

        if (result.hours >= 24)
        {
            result.hours -= (result.hours % 24) * 24;
            if (result.minutes >= 60)
            {
                result.hours += result.minutes / 60;
                result.minutes = result.minutes - 60;
            }
        }

        return result;
    }

    void changeTime(int otherH, int otherM)
    {
        hours = otherH;
        minutes = otherM;
    }

    void addMinutes(int otherMinutes)
    {
        if (otherMinutes >= 60)
        {
            hours += otherMinutes / 60;
            minutes += otherMinutes - ((otherMinutes / 60) * 60);
        }
        else
        {
            minutes += otherMinutes;
        }
    }
    
    int minutesFromTheBeggining()
    {
        return hours * 60 + minutes;
    }

    void print()
    {
        cout << hours << ":" << minutes << endl;
    }
};

int main()
{
    Time t1;
    t1.init(10, 20);
    Time t2;
    t2.init(5, 30);
    Time t3;
    t3.init(15, 50);

    (t1 + t2).print();
    (t1 - t2).print();
    (t1 * 5).print();
    cout << t1.minutesFromTheBeggining() << endl;
    (t1 + t3).print();

    t2.addMinutes(260);
    t2.print();

    return 0;
}