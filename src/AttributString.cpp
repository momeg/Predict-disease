// 
// Fichier : AttributString.cpp
// Description : Impl�mentation de la classe AttributString.
// Auteur : Lo�c Saos (loic.saos@insa-lyon.fr).
// Date de cr�ation : 30 avril 2018
// Versions :
// - 1.0 : Cr�ation de la classe.
//

#include "AttributString.hpp"

AttributString::AttributString(const string& laValeur)
	: valeur(laValeur)
{
}

TypeAttribut AttributString::getType() const
{
	return ATTRIBUT_STRING;
}

const string& AttributString::getValeur() const
{
	return valeur;
}

string AttributString::toString() const
{
	return valeur;
}