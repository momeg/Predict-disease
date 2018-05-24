#include "DefinitionAttributDouble.hpp"

#include <cassert>

DefinitionAttributDouble::DefinitionAttributDouble(){}

DefinitionAttributDouble::DefinitionAttributDouble(const string& leNom)
{
	assert(!nom.empty());
}

TypeAttribut DefinitionAttributDouble::getType() const
{
	return ATTRIBUT_DOUBLE;
}


string DefinitionAttributDouble::toString() const
{
	string s = DefinitionAttribut::toString();
	s+= " : double";
	return s;
}