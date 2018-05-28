// 
// Fichier : Attribut.cpp
// Description : Impl�mentation de la classe Attribut.
// Auteur : Lo�c Saos (loic.saos@insa-lyon.fr).
// Date de cr�ation : 30 avril 2018
// Versions :
// - 1.0 : Cr�ation de la classe.
//
#include "DefinitionAttribut.hpp"

#include <cassert>

DefinitionAttribut::DefinitionAttribut(){}

DefinitionAttribut::DefinitionAttribut(const string& leNom)
	: nom(leNom)
{
	assert(!nom.empty());
}

const string& DefinitionAttribut::getNom() const
{
	return nom;
}

void DefinitionAttribut::setIndice(size_t indice)
{
	this->indice = indice;
}

int DefinitionAttribut::getIndice() const
{
	return indice;
}

string DefinitionAttribut::toString() const
{
	string s = nom;
	return s;
}