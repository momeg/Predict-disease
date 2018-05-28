#include "DefinitionAttributDouble.hpp"

#include <cassert>

DefinitionAttributDouble::DefinitionAttributDouble(){}

DefinitionAttributDouble::DefinitionAttributDouble(const string& leNom):DefinitionAttribut(leNom){}

TypeAttribut DefinitionAttributDouble::getType() const
{
	return ATTRIBUT_DOUBLE;
}

void DefinitionAttributDouble::setMax(double newMax)
{
	if (newMax > max)
		max = newMax;
}

void DefinitionAttributDouble::setMin(double newMin)
{
	if (newMin < min)
		min = newMin;
}

double DefinitionAttributDouble::getMax() const
{
	return max;
}

double DefinitionAttributDouble::getMin() const
{
	return min;
}

string DefinitionAttributDouble::toString() const
{
	string s = DefinitionAttribut::toString();
	s+= " : double";
	return s;
}

DefinitionAttribut* DefinitionAttributDouble::cloner() const
{
	return new DefinitionAttributDouble(*this);
}
