#include <iostream>
using namespace std;

struct Planet
{
    char name[50];
    double distanceFromTheSun;
    double diameter;
    double mass;
};

void createPlanet(Planet planet)
{
    cout << "Enter planet's name: ";
    cin.ignore();
    cin.getline(planet.name, 50);
    cout << "Enter planet's distance from the sun: ";
    cin >> planet.distanceFromTheSun;
    cout << "Enter planet's diameter: ";
    cin >> planet.diameter;
    cout << "Enter planet's mass: ";
    cin >> planet.mass;
    cout << endl;
}

void printPlanet(Planet planet)
{
    cout << planet.name << " "
         << planet.distanceFromTheSun << " "
         << planet.diameter << " " 
         << planet.mass << endl;
}

double secondsFromSunToPlanet(double distance)
{
    return distance / 299792;
}

void inputData(int size, Planet planets[])
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter planet's name: ";
        cin.ignore();
        cin.getline(planets[i].name, 50);
        cout << "Enter planet's distance from the sun: ";
        cin >> planets[i].distanceFromTheSun;
        cout << "Enter planet's diameter: ";
        cin >> planets[i].diameter;
        cout << "Enter planet's mass: ";
        cin >> planets[i].mass;
        cout << endl;
    }
}

void outputData(int size, Planet planets[])
{
    for (int i = 0; i < size; i++)
    {
        cout << planets[i].name << " "
             << planets[i].distanceFromTheSun << " "
             << planets[i].diameter << " " 
             << planets[i].mass << endl;
    }
}

double biggestDiameter(int size, Planet planets[])
{
    double max;

    for (int i = 0; i < size; i++)
    {
        if (max < planets[i].diameter)
        {
            max = planets[i].diameter;
        }    
    }

    return max;
}

int main()
{
    int n;
    cout << "How many planets: ";
    cin >> n;

    Planet planets[100];

    inputData(n, planets);
    outputData(n, planets);
    cout << secondsFromSunToPlanet(planets[1].diameter) << endl;
    cout << biggestDiameter(n, planets);

    return 0;
}