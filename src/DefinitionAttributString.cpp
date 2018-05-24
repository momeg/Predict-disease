
#include "DefinitionAttributString.hpp"

#include <cassert>

DefinitionAttributString::DefinitionAttributString(){}

DefinitionAttributString::DefinitionAttributString(const string& leNom)
{
	assert(!nom.empty());
}

const virtual TypeAttribut& DefinitionAttributsString::getType() const
{
	return ATTRIBUT_STRING;
}


string DefinitionAttributsString::toString() const
{
	string s = DefinitionAttribut::toString();
	s+= " : " + "string";
	return s;
}