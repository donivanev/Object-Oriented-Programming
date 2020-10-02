#include "Stone.h"

Stone::Stone(const string n)
{
	this->name = n;
}

Stone::Stone(const Stone& other)
{
	name = other.name;
}

Stone& Stone::operator=(const Stone& other)
{
	if (this != &other)
	{
		name = other.name;
	}

	return *this;
}

bool Stone::interacts(string element)
{
	int index = 0;
	bool isTrueFire = false, isTrueEarth = false, isTrue = false;
	vector<string> v(6);
	string element1, element2;

	if (element == "Metal")
	{
		element1 = "Fire";
		element2 = "Earth";
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

	for (string s : Fire::listOfElements)
	{
		v[index] = s;
		index++;
	}

	for (string s : Water::listOfElements)
	{
		v[index] = s;
		index++;
	}

	/*for (string s : Fire::listOfElements)
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
	}*/

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

	/*for (string s : v)
	{
		if (s == element)
		{
			isTrue = true;
		}
	}

	for (string s : v)
	{
		if (s == element1 || s == element2)
		{
			isTrue = true;
		}
	}

	//return isTrueFire || isTrueEarth;
	return isTrue;*/
}

string Stone::getName()
{
	return this->name;
}