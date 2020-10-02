#include "Alchemic.h"

Alchemic::Alchemic(AlchemicalBook b, int arr[4])
{
	this->book = b;
	for (int i = 0; i < 4; i++)
	{
		values[i] = arr[i];
	}
}

bool Alchemic::isItPossibleToCreateThePhilosopherStone()
{
	bool f = false, w = false, e = false, a = false;

	if (values[0] >= book.getFireAmount())
	{
		f = true;
	}
	if (values[1] >= book.getWaterAmount())
	{
		w = true;
	}
	if (values[2] >= book.getEarthAmount())
	{
		e = true;
	}
	if (values[3] >= book.getAirAmount())
	{
		a = true;
	}

	return f && w && e && a;
}