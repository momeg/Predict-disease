// 
// Fichier : DefinitionAttributString.cpp
// Description : Implementation de la classe DefinitionAttributString.
// Auteur : Loic Saos (loic.saos@insa-lyon.fr).
// Date de creation : 30 avril 2018
// Versions :
// - 1.0 : Creation de la classe.
//

#include "DefinitionAttributString.hpp"

DefinitionAttributString::DefinitionAttributString(const string& leNom)
	: DefinitionAttribut(leNom)
{
}

TypeAttribut DefinitionAttributString::getType() const
{
	return ATTRIBUT_STRING;
}

const string& DefinitionAttributString::getValeurSignificative() const
{
	return valeurSignificative;
}

void DefinitionAttributString::setValeurSignificative(const string& laValeurSignificative)
{
	valeurSignificative = laValeurSignificative;
}

string DefinitionAttributString::toString() const
{
	return DefinitionAttribut::toString() + " : string";
}

DefinitionAttribut* DefinitionAttributString::cloner() const
{
	return new DefinitionAttributString(*this);
}
