#include "DefinitionAttributId.hpp"

#include <cassert>

DefinitionAttributString::DefinitionAttributId(){}

DefinitionAttributString::DefinitionAttributId(const string& leNom)
{
	assert(!nom.empty());
}

const virtual TypeAttribut& DefinitionAttributId::getType() const
{
	return ATTRIBUT_ID;
}


string DefinitionAttributId::toString() const
{
	string s = DefinitionAttribut::toString();
	s+= " : " + "ID";
	return s;
}