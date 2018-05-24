// 
// Fichier : AttributString.cpp
// Description : Implémentation de la classe AttributString.
// Auteur : Loïc Saos (loic.saos@insa-lyon.fr).
// Date de création : 30 avril 2018
// Versions :
// - 1.0 : Création de la classe.
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
