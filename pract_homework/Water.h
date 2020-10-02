#pragma once
#include <string>
using namespace std;

class Water
{
protected:

	int amount;
	string name;
	string listOfElements[3] = { "Fire", "Air" };

public:

	Water(const int a = 0, const string n = "");
	Water(const Water& other);
	Water& operator= (const Water& other);

	bool interacts(string element);
	void changeAmount(int number);

	string getName();
	int getAmount();
};

