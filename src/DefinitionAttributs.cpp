// 
// Fichier : Attribut.cpp
// Description : Impl�mentation de la classe Attribut.
// Auteur : Lo�c Saos (loic.saos@insa-lyon.fr).
// Date de cr�ation : 30 avril 2018
// Versions :
// - 1.0 : Cr�ation de la classe.
//
#include "DefinitionAttributs.hpp"

#include <cassert>

DefinitionAttributs::DefinitionAttributs(){}

DefinitionAttributs::DefinitionAttributs(const string& leNom, const TypeAttribut& leType)
	: nom(leNom), type(leType)
{
	assert(!nom.empty());
}

const string& DefinitionAttributs::getNom() const
{
	return nom;
}

const TypeAttribut& DefinitionAttributs::getType() const
{
	return type;
}
