#pragma once
#include "Water.h"
#include "Air.h"
#include <vector>

class Energy : public Water, public Air
{
	string name;

public:

	Energy(const string n = "");
	Energy(const Energy& other);
	Energy& operator= (const Energy& other);

	bool interacts(string element);
	string getName();
};

