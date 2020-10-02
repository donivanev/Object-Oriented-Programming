#pragma once
#include "Air.h"

class Spirit : public Air
{
	string name;

public:

	Spirit(const string n = "");
	Spirit(const Spirit& other);
	Spirit& operator= (const Spirit& other);

	bool interacts(string element);
	string getName();
};

