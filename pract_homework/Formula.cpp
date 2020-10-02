#include "Formula.h"

Formula::Formula(const string e)
{
    this->equation = e;
}

Formula::Formula(const Formula& other)
{
    this->equation = other.equation;
}

Formula& Formula::operator=(const Formula& other)
{
    if (this != &other)
    {
        this->equation = other.equation;
    }

    return *this;
}

string Formula::getEquation()
{
	return this->equation;
}

ostream& operator << (ostream& output, const Formula& f)
{
    output << f.equation;
    return output;
}