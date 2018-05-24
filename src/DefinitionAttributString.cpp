
#include "DefinitionAttributString.hpp"

#include <cassert>

DefinitionAttributString::DefinitionAttributString(){}

DefinitionAttributString::DefinitionAttributString(const string& leNom)
{
	assert(!nom.empty());
}

TypeAttribut DefinitionAttributString::getType() const
{
	return ATTRIBUT_STRING;
}


string DefinitionAttributString::toString() const
{
	string s = DefinitionAttribut::toString();
	s+= " : string";
	return s;
}