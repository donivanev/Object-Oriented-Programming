#pragma once
#include "Fire.h"
#include "Water.h"
#include <vector>

class Stone : public Fire, public Water
{
	string name;

public:

	Stone(const string n = "");
	Stone(const Stone& other);
	Stone& operator= (const Stone& other);

	bool interacts(string element);
	string getName();
};

