#include "Fire.h"

Fire::Fire(const int a, const string n)
{
	this->amount = a;
	this->name = n;
}

Fire::Fire(const Fire& other)
{
	amount = other.amount;
	name = other.name;
}

Fire& Fire::operator=(const Fire& other)
{
	if (this != &other)
	{
		amount = other.amount;
		name = other.name;
	}

	return *this;
}

bool Fire::interacts(string element)
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

void Fire::changeAmount(int number)
{
	this->amount -= number;
}

string Fire::getName()
{
	return this->name;
}

int Fire::getAmount()
{
	return this->amount;
}