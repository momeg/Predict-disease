// 
// Fichier : Attribut.cpp
// Description : Implementation de la classe DefinitionAttribut.
// Auteur : Loic Saos (loic.saos@insa-lyon.fr).
// Date de creation : 30 avril 2018
// Versions :
// - 1.0 : Creation de la classe.
//
#include "DefinitionAttribut.hpp"

#include <cassert>

DefinitionAttribut::DefinitionAttribut(const string& leNom)
	: nom(leNom)
{
	assert(!nom.empty());
}

DefinitionAttribut::~DefinitionAttribut()
{
}

const string& DefinitionAttribut::getNom() const
{
	return nom;
}

void DefinitionAttribut::setIndice(size_t indice)
{
	this->indice = indice;
}

size_t DefinitionAttribut::getIndice() const
{
	return indice;
}

string DefinitionAttribut::toString() const
{
	return nom;
}
