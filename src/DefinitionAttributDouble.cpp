#include "DefinitionAttributDouble.hpp"

#include <cassert>

DefinitionAttributString::DefinitionAttributDouble(){}

DefinitionAttributString::DefinitionAttributDouble(const string& leNom)
{
	assert(!nom.empty());
}

const virtual TypeAttribut& DefinitionAttributDouble::getType() const
{
	return ATTRIBUT_DOUBLE;
}


string DefinitionAttributDouble::toString() const
{
	string s = DefinitionAttribut::toString();
	s+= " : " + "double";
	return s;
}