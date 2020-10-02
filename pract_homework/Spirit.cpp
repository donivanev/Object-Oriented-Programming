#include "Spirit.h"

Spirit::Spirit(const string n)
{
	this->name = n;
}

Spirit::Spirit(const Spirit& other)
{
	name = other.name;
}

Spirit& Spirit::operator=(const Spirit& other)
{
	if (this != &other)
	{
		name = other.name;
	}

	return *this;
}

bool Spirit::interacts(string element)
{
	bool isTrue = false;

	for (string s : Air::listOfElements)
	{
		if (s == element)
		{
			isTrue = true;
		}
	}

	return isTrue;
}

string Spirit::getName()
{
	return this->name;
}