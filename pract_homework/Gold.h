#pragma once
#include "Metal.h"

class Gold : public Metal
{
	string name;

public:

	Gold(const string n = "");
	Gold(const Gold& other);
	Gold& operator= (const Gold& other);

	bool interacts(string element);
	string getName();
};

