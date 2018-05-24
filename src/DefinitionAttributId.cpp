#include "DefinitionAttributId.hpp"

#include <cassert>

DefinitionAttributId::DefinitionAttributId(){}

DefinitionAttributId::DefinitionAttributId(const string& leNom)
{
	assert(!nom.empty());
}

TypeAttribut DefinitionAttributId::getType() const
{
	return ATTRIBUT_ID;
}


string DefinitionAttributId::toString() const
{
	string s = DefinitionAttribut::toString();
	s+= " : ID";
	return s;
}