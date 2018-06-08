// 
// Fichier : DefinitionAttributId.cpp
// Description : Implementation de la classe DefinitionAttributId.
// Auteur : Loic Saos (loic.saos@insa-lyon.fr).
// Date de creation : 30 avril 2018
// Versions :
// - 1.0 : Creation de la classe.
//

#include "DefinitionAttributId.hpp"

DefinitionAttributId::DefinitionAttributId(const string& leNom)
	: DefinitionAttribut(leNom)
{
}

TypeAttribut DefinitionAttributId::getType() const
{
	return ATTRIBUT_ID;
}

string DefinitionAttributId::toString() const
{
	return DefinitionAttribut::toString() + " : ID";
}

DefinitionAttribut* DefinitionAttributId::cloner() const
{
	return new DefinitionAttributId(*this);
}
