#pragma once
#include <string>
using namespace std;

class Air
{
protected:

	int amount;
	string name;
	string listOfElements[4] = { "Fire", "Water", "Earth", "Air" };

public:

	Air(const int a = 0, const string n = "");
	Air(const Air& other);
	Air& operator= (const Air& other);

	bool interacts(string element);
	void changeAmount(int number);

	string getName();
	int getAmount();
};

