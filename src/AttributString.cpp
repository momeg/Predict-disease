#include "AttributString.hpp"

AttributString::AttributString(const string& leNom, const string& laValeur)
	: Attribut(leNom),
	valeur(laValeur)
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
