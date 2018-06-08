#include "DefinitionAttributId.hpp"

DefinitionAttributId::DefinitionAttributId(){}

DefinitionAttributId::DefinitionAttributId(const string& leNom):DefinitionAttribut(leNom){}

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

DefinitionAttribut* DefinitionAttributId::cloner() const
{
	return new DefinitionAttributId(*this);
}
