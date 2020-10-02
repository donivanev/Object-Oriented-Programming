#include "Metal.h"

Metal::Metal(const string n)
{
	this->name = n;
}

Metal::Metal(const Metal& other)
{
	name = other.name;
}

Metal& Metal::operator=(const Metal& other)
{
	if (this != &other)
	{
		name = other.name;
	}

	return *this;
}

bool Metal::interacts(string element)
{
	int index = 0;
	bool isTrueFire = false, isTrueEarth = false, isTrue = false;
	vector<string> v(6);
	string element1, element2;

	if (element == "Stone")
	{
		element1 = "Fire";
		element2 = "Water";
	}
	else if(element == "Energy")
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

	for (string s : Fire::listOfElements)
	{
		v[index] = s;
		index++;
	}

	for (string s : Earth::listOfElements)
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

string Metal::getName()
{
	return this->name;
}