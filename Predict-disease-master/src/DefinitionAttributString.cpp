#include "DefinitionAttributString.hpp"

DefinitionAttributString::DefinitionAttributString(){}

DefinitionAttributString::DefinitionAttributString(const string& leNom):DefinitionAttribut(leNom){}

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

DefinitionAttribut* DefinitionAttributString::cloner() const
{
	return new DefinitionAttributString(*this);
}
