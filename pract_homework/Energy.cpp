#include "Energy.h"

Energy::Energy(const string n)
{
	this->name = n;
}

Energy::Energy(const Energy& other)
{
	name = other.name;
}

Energy& Energy::operator=(const Energy& other)
{
	if (this != &other)
	{
		name = other.name;
	}

	return *this;
}

bool Energy::interacts(string element)
{
	int index = 0;
	bool isTrueFire = false, isTrueEarth = false, isTrue = false;
	vector<string> v(8);
	string element1, element2;

	if (element == "Metal")
	{
		element1 = "Fire";
		element2 = "Earth";
	}
	else if (element == "Stone")
	{
		element1 = "Fire";
		element2 = "Water";
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

 	for (string s : Water::listOfElements)
	{
		v[index] = s;
		index++;
	}

	for (string s : Air::listOfElements)
	{
		v[index] = s;
		index++;
	}

	if (element1 != "" && element2 != "")
	{
		for (string s : v)
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
		for (string s : v)
		{
			if (s == element)
			{
				isTrue = true;
			}
		}

		return isTrue;
	}
}

string Energy::getName()
{
	return this->name;
}