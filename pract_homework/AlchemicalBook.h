#pragma once
#include <vector>
#include <iostream>
#include "Formula.h"
using namespace std;

class AlchemicalBook
{
	vector<Formula> arrayOfFormulas;
	vector<string> splittedFormula;
	int basicElements[4];

public:

	void splitStringByPlusOrEqualSign(string cmd, vector<string>& v);
	void filter(Formula f);
	void push(Formula f);
	void print();

	int getFireAmount();
	int getWaterAmount();
	int getEarthAmount();
	int getAirAmount();
};

