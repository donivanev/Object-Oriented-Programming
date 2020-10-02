#pragma once
#include "AlchemicalBook.h"

class Alchemic
{
	AlchemicalBook book;
	int values[4];

public:

	Alchemic(AlchemicalBook book, int arr[4]);
	bool isItPossibleToCreateThePhilosopherStone();
};

