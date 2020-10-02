#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Formula
{
	string equation;

public:

	Formula(const string e = "");
	Formula(const Formula& other);
	Formula& operator= (const Formula& other);

	string getEquation();

	friend ostream& operator << (ostream& output, const Formula& f);
};

