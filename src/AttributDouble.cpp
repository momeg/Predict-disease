#include "AttributDouble.hpp"

AttributDouble::AttributDouble(const string& leNom, double laValeur)
	: Attribut(leNom),
	valeur(laValeur)
{
}

TypeAttribut AttributDouble::getType() const
{
	return ATTRIBUT_DOUBLE;
}

double AttributDouble::getValeur() const
{
	return valeur;
}
