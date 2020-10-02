#include "Earth.h"

Earth::Earth(const int a, const string n)
{
	this->amount = a;
	this->name = n;
}

Earth::Earth(const Earth& other)
{
	amount = other.amount;
	name = other.name;
}

Earth& Earth::operator=(const Earth& other)
{
	if (this != &other)
	{
		amount = other.amount;
		name = other.name;
	}

	return *this;
}

bool Earth::interacts(string element)
{
	string element1, element2;
	bool isTrue = false;

	if (element == "Stone")
	{
		element1 = "Fire";
		element2 = "Water";
	}
	else if (element == "Energy")
	{
		element1 = "Water";
		element2 = "Air";
	}
	else if (element == "Spirit")
	{
		element1 = "Air";
		element2 = "Air";
	}
	else if (element == "Gold")
	{
		element1 = "Fire";
		element2 = "Earth";
	}

	/*for (string s : this->listOfElements)
	{
		if (s == element)
		{
			return true;
		}
	}

	return false;*/

	if (element1 != "" && element2 != "")
	{
		for (string s : this->listOfElements)
		{
			if (s == element1 || s == element2)
			{
				isTrue = true;
			}
		}

		return isTrue;
	}
	else
	{
		for (string s : this->listOfElements)
		{
			if (s == element)
			{
				isTrue = true;
			}
		}

		return isTrue;
	}
}

void Earth::changeAmount(int number)
{
	this->amount -= number;
}

string Earth::getName()
{
	return this->name;
}

int Earth::getAmount()
{
	return this->amount;
}