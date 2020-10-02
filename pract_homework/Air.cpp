#include "Air.h"

Air::Air(const int a, const string n)
{
	this->amount = a;
	this->name = n;
}

Air::Air(const Air& other)
{
	amount = other.amount;
	name = other.name;
}

Air& Air::operator=(const Air& other)
{
	if (this != &other)
	{
		amount = other.amount;
		name = other.name;
	}

	return *this;
}

bool Air::interacts(string element)
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

void Air::changeAmount(int number)
{
	this->amount -= number;
}

string Air::getName()
{
	return this->name;
}

int Air::getAmount()
{
	return this->amount;
}