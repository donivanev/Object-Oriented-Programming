#pragma once
#include <string>
using namespace std;

class Fire
{
protected:

	int amount;
	string name;
	string listOfElements[3] = { "Fire", "Water", "Earth" };

public:

	Fire(const int a = 0, const string n = "");
	Fire(const Fire& other);
	Fire& operator= (const Fire& other); 

	bool interacts(string element);
	void changeAmount(int number);

	string getName();
	int getAmount();
};

