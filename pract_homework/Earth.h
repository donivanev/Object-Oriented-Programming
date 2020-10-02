#pragma once
#include <string>
using namespace std;

class Earth
{
protected:

	int amount;
	string name;
	string listOfElements[3] = { "Fire", "Water", "Air" };

public:

	Earth(const int a = 0, const string n = "");
	Earth(const Earth& other);
	Earth& operator= (const Earth& other);

	bool interacts(string element);
	void changeAmount(int number);

	string getName();
	int getAmount();
};

