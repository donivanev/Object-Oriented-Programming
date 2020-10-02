#include "Gold.h"

Gold::Gold(const string n)
{
	this->name = n;
}

Gold::Gold(const Gold& other)
{
	name = other.name;
}

Gold& Gold::operator=(const Gold& other)
{
	if (this != &other)
	{
		name = other.name;
	}

	return *this;
}

bool Gold::interacts(string element)
{
	bool isTrueFire = false;
	bool isTrueEarth = false;

	for (string s : Fire::listOfElements)
	{
		if (s == element)
		{
			isTrueFire = true;
		}
	}
	for (string s : Earth::listOfElements)
	{
		if (s == element)
		{
			isTrueEarth = true;
		}
	}

	return isTrueFire || isTrueEarth;
}

string Gold::getName()
{
	return this->name;
}