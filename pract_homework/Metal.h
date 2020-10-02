#pragma once
#include "Fire.h"
#include "Earth.h"
#include <vector>
using namespace std;

class Metal : public Fire, public Earth
{
	string name;

public:

	Metal(const string n = "");
	Metal(const Metal& other);
	Metal& operator= (const Metal& other);

	bool interacts(string element);
	string getName();
};

