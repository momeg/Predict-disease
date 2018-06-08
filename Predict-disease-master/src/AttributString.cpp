// 
// Fichier : AttributString.cpp
// Description : Implementation de la classe AttributString.
// Auteur : Loic Saos (loic.saos@insa-lyon.fr).
// Date de creation : 30 avril 2018
// Versions :
// - 1.0 : Creation de la classe.
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

Attribut* AttributString::cloner() const
{
	return new AttributString(*this);
}

const string& AttributString::getValeur() const
{
	return valeur;
}
